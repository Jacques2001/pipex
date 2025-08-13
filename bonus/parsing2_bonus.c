/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:16:10 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/13 13:41:18 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	free_av(char **split, t_vars *vars)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (i < vars->av_i)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

void	free_all(t_vars *vars)
{
	if (vars->pid)
		free(vars->pid);
	if (vars->av)
		free_av(vars->av, vars);
	if (vars->path)
		free_split(vars->path);
	if (vars)
		free(vars);
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

void	vars_init(t_vars *vars, char **av, char **env, int ac)
{
	int	i;

	i = 0;
	vars->ac = ac;
	vars->av_i = 0;
	vars->fd_in = 0;
	vars->fd_out = 0;
	vars->path = NULL;
	vars->pid = malloc((ac - 3) * sizeof(pid_t));
	if (!vars->pid)
	{
		free_all(vars);
		exit(1);
	}
	vars->env_cpy = env;
	vars->av_cpy = av;
	vars->av = malloc((ac - 3) * sizeof(char *));
	if (!vars->av)
	{
		free_all(vars);
		exit(1);
	}
}
