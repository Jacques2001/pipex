/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:34:38 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/28 17:08:11 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/*int main()
{
	char str[] = "bonjourno";
	char c = 'n';
	char *resultat = ft_memchr(str, c, 2);
	printf("%s\n", resultat);
	printf("%s\n", memchr(str, c, 2));
	return (0);
}*/