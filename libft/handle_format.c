/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:36:34 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 15:00:46 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_string(const char *format, va_list args, int *i)
{
	char	*str;
	int		count;

	count = 0;
	if (format[*i] == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
		{
			write(1, "(null)", 6);
			count += 6;
		}
		else
			count += print_string(str);
	}
	return (count);
}

int	handle_format3(const char *format, va_list args, int *i)
{
	unsigned int	nb;
	int				count;

	count = 0;
	if (format[*i] == '%')
	{
		write(1, "%%", 1);
		count++;
	}
	else if (format[*i] == 'u')
	{
		nb = va_arg(args, unsigned int);
		count += print_unsigned(nb);
	}
	else
		count += handle_string(format, args, i);
	return (count);
}

int	handle_format2(const char *format, va_list args, int *i)
{
	unsigned int	hex;
	void			*ptr;
	int				count;

	count = 0;
	if (format[*i] == 'x' || format[*i] == 'X')
	{
		hex = va_arg(args, unsigned int);
		if (format[*i] == 'X')
			count += print_hexa(hex);
		else if (format[*i] == 'x')
			count += print_hex(hex);
	}
	else if (format[*i] == 'p')
	{
		ptr = va_arg(args, void *);
		count += print_address(ptr);
	}
	else
		count += handle_format3(format, args, i);
	return (count);
}

int	handle_format(const char *format, va_list args, int *i)
{
	char	c;
	int		count;
	int		nbr;

	count = 0;
	(*i)++;
	if (format[*i] == 'c')
	{
		c = va_arg(args, int);
		count += print_char(c);
	}
	else if (format[*i] == 'd' || format[*i] == 'i')
	{
		nbr = va_arg(args, int);
		count += print_nbr(nbr);
	}
	else
		count += handle_format2(format, args, i);
	return (count);
}
