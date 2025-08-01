/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:36:16 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 15:30:13 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	va_start(args, format);
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += handle_format(format, args, &i);
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

// int main()
// {
// 	char str[] = "Hello";
// 	int x = 0;
// 	// ft_printf("%c %s %p %d %i %u %x %X %%\n", 'c', str, &x, x, x, x, x, x);
// 	// printf("%c %s %p %d %i %u %x %X %%\n", 'c', str, &x, x, x, x, x, x);
// 	// ft_printf(" NULL %s NULL ", NULL);
// 	ft_printf("%p\n", &x);
// 	printf("%p\n", &x);
// 	return (0);
// }