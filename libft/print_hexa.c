/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:36:55 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 15:02:23 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned int nb)
{
	char	*tab;
	int		count;

	count = 0;
	tab = "0123456789ABCDEF";
	if (nb >= 16)
		count += print_hexa(nb / 16);
	write(1, &tab[nb % 16], 1);
	count++;
	return (count);
}
