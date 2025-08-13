/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:16:10 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/13 16:58:58 by jchiu            ###   ########.fr       */
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

// void	heredoc(char ***av, int *ac, t_vars *vars)
// {
// 	char *line;
// 	int pipe_fd[2];
	
// 	line = NULL;
// 	if (pipe(pipe_fd) < 0)
// 		return (perror("pipe"), exit(1));
// 	while (1)
// 	{
// 		ft_printf("pipe heredoc> ");
// 		line = get_next_line(0);
// 		if (!line)
// 			break;
// 		if (ft_strncmp(line, (*av)[2], ft_strlen((*av)[2])) == 0)
// 		{
// 			free(line);
// 			break;
// 		}
// 		write(pipe_fd[1], line, ft_strlen(line));
// 		free(line);
// 	}
// 	close(pipe_fd[1]); // écriture : fermée car plus utilisée
// 	// if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
// 	// 	exit(1);
// 	// close(pipe_fd[1]);
// 	// close(pipe_fd[0]);
// 	if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
// 		exit(1);
// 	close(pipe_fd[0]); // lecture : fermée car dupliquée sur STDIN
// 	// close(pipe_fd[1]); // écriture : fermée car plus utilisée
// 	(*av) += 1;
// 	(*ac)--;
// 	vars->ac--;
// }

void	heredoc(t_vars *vars, int *ac, char ***av)
{
	int		pipe_fd[2];
	char	*line;

	if (pipe(pipe_fd) < 0)
		return (perror("pipe"), free_all(vars), exit(1));
	while (1)
	{
		ft_printf("pipe heredoc> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break;
		if (ft_strncmp(line, (*av)[2], ft_strlen((*av)[2])) == 0
			&& line[ft_strlen((*av)[2])] == '\n')
		{
			free(line);
			break;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
	close(pipe_fd[1]);        
	vars->fd_in = pipe_fd[0]; 
	(*av) += 1;               
	(*ac)--;                 
	vars->ac--;
}
