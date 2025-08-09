/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:37 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/09 16:20:09 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex.h"

void	ft_waitpid(t_vars *vars)
{
	int	status1;
	int	status2;

	waitpid(vars->pid_1, &status1, 0);
	waitpid(vars->pid_2, &status2, 0);
	if (WIFEXITED(status1) && WEXITSTATUS(status1) != 0)
		return (free_all(vars), exit(0));
	if (WIFEXITED(status2) && WEXITSTATUS(status2) != 0)
		return (free_all(vars), exit(1));
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
		return (free_split(split_cmd), free_all(vars), exit(127));
	if (execve(cmd, split_cmd, vars->env_cpy) < 0)
		return (perror("error"), free_all(vars), exit(1));
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
		return (free_split(split_cmd), free_all(vars), exit(127));
	execve(cmd, split_cmd, vars->env_cpy);
	perror("error");
	exit(1);
}

void	pipex(t_vars *vars, char **av)
{
	int	pipefd[2];

	if (pipe(pipefd) < 0)
		return (perror("Pipe"), free_all(vars), exit(1));
	vars->pid_1 = fork();
	if (vars->pid_1 < 0)
		return (perror("Fork"), free_all(vars), exit(1));
	if (vars->pid_1 == 0)
		child1_process(vars, av, pipefd);
	vars->pid_2 = fork();
	if (vars->pid_2 < 0)
		return (perror("Fork"), free_all(vars), exit(1));
	if (vars->pid_2 == 0)
		child2_process(vars, av, pipefd);
	close(vars->fd_in);
	close(vars->fd_out);
	close(pipefd[0]);
	close(pipefd[1]);
	ft_waitpid(vars);
	free_all(vars);
}
