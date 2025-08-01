/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:36:50 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 15:02:30 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int nb)
{
	char	*tab;
	int		count;

	count = 0;
	tab = "0123456789abcdef";
	if (nb >= 16)
		count += print_hex(nb / 16);
	write(1, &tab[nb % 16], 1);
	count++;
	return (count);
}
