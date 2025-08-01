/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:35:59 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 13:36:02 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	x = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i])
		str[x++] = s1[i++];
	i = 0;
	while (s2[i])
		str[x++] = s2[i++];
	str[x] = '\0';
	return (str);
}
/*
int	main(void)
{
	char s1[] = "Hello";
	char s2[] = "World 42";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}*/