/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:36:56 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 13:36:58 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (start >= ft_strlen(s))
	{
		str = malloc(1 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int main()
{
	char str[] = "tripouille";
	printf("%s\n", ft_substr(str, 100, 1));
}*/