/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:36:36 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 13:36:40 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	start;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		k = 0;
		start = i;
		while (haystack[start] == needle[k] && start < len)
		{
			start++;
			k++;
			if (needle[k] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

/*int main()
{
	char hay[] = "aaabcabcd";
	char needle[] = "cd";
	printf("%s\n", ft_strnstr(hay, needle, 8));
	printf("%s\n", strnstr(hay, needle, 8));
	return (0);
}*/