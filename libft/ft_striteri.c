/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:35:55 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 14:05:09 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return ;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
