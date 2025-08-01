/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:14:16 by jchiu             #+#    #+#             */
/*   Updated: 2025/07/23 14:21:38 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*g_ft_strjoin(char *s1, char *s2);
int		g_ft_strlen(char *str);
char	*g_ft_strdup(char *s1);
char	*g_ft_substr(char *s, int start, int len);
int		check_line(char *to_check);

#endif