/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:36:38 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 17:26:16 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_for_adress(unsigned long nb)
{
	const char	*tab;
	int			count;

	tab = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
		count += print_hex_for_adress(nb / 16);
	write(1, &tab[nb % 16], 1);
	count++;
	return (count);
}

int	print_address(void *ptr)
{
	unsigned long	nbr;

	nbr = (unsigned long)ptr;
	if (!ptr)
	{
		(write(1, "(nil)", 5));
		return (5);
	}
	write(1, "0x", 2);
	return (print_hex_for_adress(nbr) + 2);
}
