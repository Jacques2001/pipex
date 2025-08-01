/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:36:42 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 13:47:00 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = ft_strlen(s);
	str = (char *)s;
	while (i != 0)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i--;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "Hallall Jcques";
	char c = '\0';
	char *resultat = ft_strrchr(str, c);
	printf("%s\n", resultat);
	printf("%s\n", strrchr(str, c));
	return (0);
}*/