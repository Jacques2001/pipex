/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:16:10 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/12 18:16:11 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

int	is_empty_cmd(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac - 1)
	{
		if (!av[i] || !av[i][0])
			return (1);
		i++;
	}
	return (0);
}

void	free_all(t_vars *vars)
{
	// if (vars->pid)
	// 	free(vars->pid);
	if (vars->av)
		free_split(vars->av);
	if (vars->path)
		free_split(vars->path);
	if (vars)
		free(vars);
}

void	close_all(t_vars *vars, int *pipefd)
{
	close(vars->fd_in);
	close(vars->fd_out);
	close(pipefd[0]);
	close(pipefd[1]);
}

void	close_all_all(t_vars *vars, int (*pipefd)[2], int ac)
{
	int	i;

	i = 0;
	close(vars->fd_in);
	close(vars->fd_out);
	while (i < ac - 4)
	{
		close(pipefd[i][0]);
		close(pipefd[i][1]);
		i++;
	}
}

void	close_all_pipes(int (*pipefd)[2], int ac)
{
	int	i;

	i = 0;
	while (i < ac - 4)
	{
		close(pipefd[i][0]);
		close(pipefd[i][1]);
		i++;
	}
}
