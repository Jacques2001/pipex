/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:16:10 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/16 17:23:56 by jchiu            ###   ########.fr       */
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
		if (pipefd[i][0] >= 0)
			close(pipefd[i][0]);
		if (pipefd[i][1] >= 0)
			close(pipefd[i][1]);
		i++;
	}
}

void	vars_init(t_vars *vars, char **av, char **env, int ac)
{
	int	i;

	i = 0;
	vars->fd_null = -1;
	vars->ac = ac;
	vars->av_i = 0;
	vars->fd_in = -1;
	vars->fd_out = -1;
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

void	heredoc(t_vars *vars, int *ac, char ***av)
{
	int		pipe_fd[2];
	char	*line;

	vars->fd_out = open((*av)[vars->ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (*ac < 6)
		return (ft_printf("Argument not valid\n"), free_all(vars), exit(1));
	if (pipe(pipe_fd) < 0)
		return (perror("pipe"), free_all(vars), exit(1));
	while (1)
	{
		ft_printf("pipe heredoc> ");
		line = get_next_line(0, 0);
		if (!line)
			break ;
		if (ft_strncmp(line, (*av)[2], ft_strlen((*av)[2])) == 0
			&& line[ft_strlen((*av)[2])] == '\n')
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
	(void)(close(pipe_fd[1]), vars->fd_in = pipe_fd[0], (*av)++, (*ac)--,
		vars->ac--, get_next_line(0, 1));
}
