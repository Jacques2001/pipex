/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:34:46 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 13:34:47 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (str1[i] - str2[i]);
	}
	return (0);
}

/*int main()
{
	char s1[] = "Hello";
	char s2[] = "jacques";
	char s4[] = {0, 0, 42, 0};
	char s3[] = {0, 0, 42, 0};
	int resultat = ft_memcmp(s3, s4, 4);
	printf("%d\n", resultat);
	printf("%d\n", memcmp(s3, s4, 4));
	return (0);
}*/