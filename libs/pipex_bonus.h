/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:44 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/09 12:32:47 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_vars
{
	char	*av2;
	char	*av3;
	int		fd_in;
	int		fd_out;
	pid_t	pid_1;
	pid_t	pid_2;
	char	**path;
	char	**env_cpy;
	char	**av_cpy;
}			t_vars;

char		**find_path(char **env);
int			check_av2(char **path, char **av, t_vars *vars);
int			check_av3(char **path, char **av, t_vars *vars);
void		vars_init(t_vars *vars, char **av, char **env);
void		child1_process(t_vars *vars, char **av, int *pipefd);
void		child2_process(t_vars *vars, char **av, int *pipefd);
int			pipex(t_vars *vars, char **av, int ac);
void		free_all(t_vars *vars);

#endif