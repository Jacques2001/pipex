/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:35:35 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 13:35:38 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/*int main()
{
	char str[] = "tripouille";
	char c = 't';
	char *resultat = ft_strchr(str, c + 256);
	printf("%s\n", resultat);
	printf("%s\n", strchr(str, c + 256));
	return (0);
}*/