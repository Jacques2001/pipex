/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:37 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/09 12:33:07 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

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

void	child1_process(t_vars *vars, char **av, int *pipefd)
{
	char	*cmd;
	char	**split_cmd;

	split_cmd = ft_split(av[2], ' ');
	if (dup2(vars->fd_in, STDIN_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
	close(pipefd[0]);
	close(vars->fd_in);
	close(pipefd[1]);
	close(vars->fd_out);
	cmd = vars->av2;
	if (!cmd)
		return ;
	if (execve(cmd, split_cmd, vars->env_cpy) < 0)
		return (perror("error"), free_all(vars), exit(127));
}

void	child2_process(t_vars *vars, char **av, int *pipefd)
{
	char	*cmd;
	char	**split_cmd;

	split_cmd = ft_split(av[3], ' ');
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
	if (dup2(vars->fd_out, STDOUT_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
	close(pipefd[0]);
	close(vars->fd_in);
	close(pipefd[1]);
	close(vars->fd_out);
	cmd = vars->av3;
	if (!cmd)
		return ;
	execve(cmd, split_cmd, vars->env_cpy);
	perror("error");
	exit(127);
}

int	pipex(t_vars *vars, char **av, int ac)
{
	int	pipefd[ac / 2];

	if (pipe(pipefd) < 0)
		return (perror("Pipe"), free_all(vars), exit(1), 1);
	vars->pid_1 = fork();
	if (vars->pid_1 < 0)
		return (perror("Fork"), free_all(vars), exit(1), 1);
	if (vars->pid_1 == 0)
		child1_process(vars, av, pipefd);
	vars->pid_2 = fork();
	if (vars->pid_2 < 0)
		return (perror("Fork"), free_all(vars), exit(1), 1);
	if (vars->pid_2 == 0)
		child2_process(vars, av, pipefd);
	close(vars->fd_in);
	close(vars->fd_out);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(vars->pid_1, NULL, 0);
	waitpid(vars->pid_2, NULL, 0);
	free_all(vars);
	return (0);
}
