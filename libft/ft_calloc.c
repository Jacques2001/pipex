/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:32:55 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 13:38:07 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	if (count == (size_t)-2147483648 || count == (size_t)2147483647)
		return (NULL);
	tab = malloc(count * size);
	if (tab == NULL)
		return (NULL);
	ft_memset(tab, 0, count * size);
	return (tab);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_calloc(5, 4));
	return (0);
}*/