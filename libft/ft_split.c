/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:35:32 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/03 15:23:01 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_str(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

int	count_word(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((i == 0 && str[i] != c) || (str[i] != c && str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

int	count_letter(char const *str, char c, int x)
{
	int	i;

	i = 0;
	while (str[x] != c && str[x])
	{
		x++;
		i++;
	}
	return (i);
}

void	fill_split(char **split, char const *str, char c)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (str[y])
	{
		if ((y == 0 && str[y] != c) || (str[y] != c && str[y - 1] == c))
		{
			while (str[y] != c && str[y])
				split[i][x++] = str[y++];
			split[i][x] = '\0';
			i++;
			x = 0;
		}
		else
			y++;
	}
	split[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		x;
	char	**split;

	i = 0;
	x = 0;
	split = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (s[x])
	{
		if ((x == 0 && s[x] != c) || (s[x] != c && s[x - 1] == c))
		{
			split[i] = malloc((count_letter(s, c, x) + 1) * sizeof(char));
			if (split[i] == NULL)
				return (free_str(split, i), NULL);
			i++;
		}
		x++;
	}
	fill_split(split, s, c);
	return (split);
}
