/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:14:13 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/14 11:12:31 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_and_free_stash(char **stash, char *line)
{
	char	*new_stash;

	new_stash = g_ft_substr((*stash), g_ft_strlen(line), g_ft_strlen(*stash));
	free(*stash);
	*stash = NULL;
	return (new_stash);
}

char	*extract_line(char **stash)
{
	int		x;
	char	*line;

	if (!*stash)
		return (0);
	x = check_line(*stash);
	line = g_ft_substr(*stash, 0, x + 1);
	if (!line)
		return (free(*stash), *stash = NULL, NULL);
	*stash = new_and_free_stash(stash, line);
	if (!*stash)
		return (free(line), NULL);
	return (line);
}

char	*last_line_check(char **stash, char *buf)
{
	char	*line;

	line = g_ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	free(buf);
	if (line != NULL)
		return (line);
	return (NULL);
}

void	fill_stash(char **stash, char *buf, int nb_read)
{
	char	*tmp;

	if (*stash == NULL)
	{
		*stash = g_ft_strdup(buf);
		if (*stash == NULL)
			return ;
	}
	else if (nb_read != 0)
	{
		tmp = g_ft_strjoin(*stash, buf);
		if (tmp == NULL)
		{
			free(*stash);
			*stash = NULL;
			return ;
		}
		free(*stash);
		*stash = tmp;
	}
}

char	*get_next_line(int fd, int free_flag)
{
	static char	*stash;
	char		*buf;
	int			nb_read;

	nb_read = -1;
	if (fd < 0 || free_flag)
		return (free_last_gnl(free_flag, stash));
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), stash = NULL, NULL);
	while (nb_read != 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == -1)
			return (free(buf), free(stash), stash = NULL, NULL);
		buf[nb_read] = '\0';
		fill_stash(&stash, buf, nb_read);
		if (!stash)
			return (free(buf), NULL);
		if (check_line(stash) >= 0)
			return (free(buf), extract_line(&stash));
	}
	if (stash && *stash)
		return (last_line_check(&stash, buf));
	return (free(stash), stash = NULL, free(buf), NULL);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i = 1;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("[%d]: %s", i, line);
// 		free(line);
// 		i++;
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }