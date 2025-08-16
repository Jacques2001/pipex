/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:19:07 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/16 14:03:00 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex.h"

int	is_empty_cmd(char *cmd)
{
	if (!cmd || cmd[0] == '\0')
		return (1);
	return (0);
}

void	free_all(t_vars *vars)
{
	if (vars->av2)
		free(vars->av2);
	if (vars->av3)
		free(vars->av3);
	if (vars->path)
		free_split(vars->path);
	if (vars)
		free(vars);
}

void	close_all(int *pipefd, t_vars *vars)
{
	if (pipefd[0] >= 0)
		close(pipefd[0]);
	if (pipefd[1] >= 0)
		close(pipefd[1]);
	if (vars->fd_in >= 0)
		close(vars->fd_in);
	if (vars->fd_out >= 0)
		close(vars->fd_out);
}
