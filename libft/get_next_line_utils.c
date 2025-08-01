/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:14:11 by jchiu             #+#    #+#             */
/*   Updated: 2025/07/23 14:22:18 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*g_ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	x = 0;
	str = malloc((g_ft_strlen(s1) + g_ft_strlen(s2) + 1) * sizeof(char));
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

int	g_ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*g_ft_strdup(char *s1)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc((g_ft_strlen(s1) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*g_ft_substr(char *s, int start, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	if (start >= g_ft_strlen(s))
		return (g_ft_strdup(""));
	if (len > g_ft_strlen(s) - start)
		len = g_ft_strlen(s) - start;
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

int	check_line(char *to_check)
{
	int	i;

	i = 0;
	if (!to_check)
		return (-1);
	while (to_check[i])
	{
		if (to_check[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
