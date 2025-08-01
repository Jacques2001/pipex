/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:36:06 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 13:36:07 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	k = 0;
	i = ft_strlen(dst);
	if (dstsize == 0)
		return (src_len);
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	while (src[k] && k < dstsize - 1 - dst_len)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

/*int main()
{
	char src[] = "AAAAAAAAA";
	char dst[30] = {0};
	printf("%lu\n", strlcat(dst, src, 6));
	printf("%zu\n", ft_strlcat(dst, src, 6));
	return (0);
}*/