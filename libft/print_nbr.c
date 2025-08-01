/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:37:00 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 15:07:27 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	print_nbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		count += 2;
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		count++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += print_nbr(nb / 10);
		count += print_nbr(nb % 10);
	}
	else
		count += print_char(nb + '0');
	return (count);
}
