/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:16:18 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/15 12:06:04 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	first_child_process(t_vars *vars, char **av, int (*pipefd)[2])
{
	char	**split_cmd;
	int		fd_null;

	split_cmd = ft_split(av[2], ' ');
	if (vars->fd_in >= 0)
		dup2(vars->fd_in, STDIN_FILENO);
	else
	{
		fd_null = open("/dev/null", O_RDONLY);
		dup2(fd_null, STDIN_FILENO);
		close(fd_null);
	}
	if (dup2(pipefd[0][1], STDOUT_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd),
			free_all(vars), exit(1));
	close(pipefd[0][0]);
	close(pipefd[0][1]);
	close(vars->fd_in);
	close(vars->fd_out);
	if (!vars->av[0] || access(vars->av[0], X_OK) != 0)
		return (perror("error"),
			free_split(split_cmd), free(pipefd), free_all(vars), exit(127));
	if (execve(vars->av[0], split_cmd, vars->env_cpy) < 0)
		return (perror("error"), free(pipefd), free_all(vars), exit(1));
}

void	last_child_process(t_vars *vars, char **av, int (*pipefd)[2])
{
	char	*cmd;
	char	**split_cmd;

	split_cmd = ft_split(av[vars->ac - 2], ' ');
	if (dup2(pipefd[vars->ac - 5][0], STDIN_FILENO) < 0)
		return (perror("dup2"), free(pipefd), free_split(split_cmd),
			free_all(vars), exit(1));
	if (dup2(vars->fd_out, STDOUT_FILENO) < 0)
		return (perror("dup2"), free(pipefd), free_split(split_cmd),
			free_all(vars), exit(1));
	close_all_pipes(pipefd, vars->ac);
	close(vars->fd_in);
	close(vars->fd_out);
	cmd = vars->av[vars->ac - 4];
	if (!cmd || access(cmd, X_OK) != 0)
		return (perror("error"),
			free_split(split_cmd), free(pipefd), free_all(vars), exit(127));
	if (execve(cmd, split_cmd, vars->env_cpy) < 0)
		return (perror("error"), free(pipefd), free_all(vars), exit(1));
}

void	middle_child_process(t_vars *vars, char **av, int (*pipefd)[2], int i)
{
	char	*cmd;
	char	**split_cmd;

	split_cmd = ft_split(av[i + 2], ' ');
	if (dup2(pipefd[i - 1][0], STDIN_FILENO) < 0)
		return (perror("dup2"), free(pipefd), free_split(split_cmd),
			free_all(vars), exit(1));
	if (dup2(pipefd[i][1], STDOUT_FILENO) < 0)
		return (perror("dup2"), free(pipefd), free_split(split_cmd),
			free_all(vars), exit(1));
	close_all_pipes(pipefd, vars->ac);
	close(vars->fd_in);
	close(vars->fd_out);
	cmd = vars->av[i];
	if (!cmd || access(cmd, X_OK) != 0)
		return (perror("error"), free(pipefd),
			free_split(split_cmd), free_all(vars), exit(127));
	if (execve(cmd, split_cmd, vars->env_cpy) < 0)
		return (perror("error"), free(pipefd), free_all(vars), exit(1));
}

void	exec_children(t_vars *vars, char **av, int (*pipefd)[2])
{
	int	i;

	i = 1;
	vars->pid[0] = fork();
	if (vars->pid[0] < 0)
		return (perror("Fork"), free(pipefd), free_all(vars), exit(1));
	if (vars->pid[0] == 0)
		first_child_process(vars, av, pipefd);
	while (i < vars->ac - 4)
	{
		vars->pid[i] = fork();
		if (vars->pid[i] < 0)
			return (perror("Fork"), free(pipefd), free_all(vars), exit(1));
		if (vars->pid[i] == 0)
			middle_child_process(vars, av, pipefd, i);
		i++;
	}
	vars->pid[vars->ac - 4] = fork();
	if (vars->pid[vars->ac - 4] < 0)
		return (perror("Fork"), free(pipefd), free_all(vars), exit(1));
	if (vars->pid[vars->ac - 4] == 0)
		last_child_process(vars, av, pipefd);
}

void	pipex(t_vars *vars, char **av)
{
	int	(*pipefd)[2];
	int	i;

	pipefd = malloc(sizeof(int [vars->ac][2]));
	i = 0;
	if (!pipefd)
		return (free_all(vars), exit(1));
	while (i < vars->ac - 4)
	{
		if (pipe(pipefd[i]) < 0)
			return (perror("Pipe"), free(pipefd), free_all(vars), exit(1));
		i++;
	}
	exec_children(vars, av, pipefd);
	close_all_pipes(pipefd, vars->ac);
	close(vars->fd_in);
	close(vars->fd_out);
	while (wait(NULL) > 0)
		;
	free(pipefd);
	free_all(vars);
}
