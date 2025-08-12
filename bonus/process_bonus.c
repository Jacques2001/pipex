#include "../libs/pipex_bonus.h"

void	first_child_process(t_vars *vars, char **av, int (*pipefd)[2])
{
	printf("Je suis dans le first\n");
	char	*cmd;
	char	**split_cmd;

	split_cmd = ft_split(av[2], ' ');
	if (dup2(vars->fd_in, STDIN_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
	if (dup2(pipefd[0][1], STDOUT_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
	close(pipefd[0][0]);
	close(pipefd[0][1]);
	close(vars->fd_in);
	close(vars->fd_out);
	cmd = vars->av[0];
	if (!cmd)
		return (free_split(split_cmd), free_all(vars), exit(127));
	if (execve(cmd, split_cmd, vars->env_cpy) < 0)
		return (perror("execve first"), free_all(vars), exit(1));
}

void	last_child_process(t_vars *vars, char **av, int (*pipefd)[2], int ac)
{
	printf("Je suis dans le last\n");
	char	*cmd;
	char	**split_cmd;
	
	split_cmd = ft_split(av[ac - 2], ' ');
	if (dup2(pipefd[ac - 5][0], STDIN_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
	if (dup2(vars->fd_out, STDOUT_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
	for (int i = 0; i < ac - 4; i++)
	{
		close(pipefd[i][0]); // lecture
		close(pipefd[i][1]); // écriture
	}
	close(vars->fd_in);
	close(vars->fd_out);
	cmd = vars->av[ac - 4];
	if (!cmd)
		return (free_split(split_cmd), free_all(vars), exit(127));
	execve(cmd, split_cmd, vars->env_cpy);
	perror("execve last");
	exit(1);
}

void    middle_child_process(t_vars *vars, char **av, int (*pipefd)[2], int ac, int i)
{
	printf("Je suis rentre dans le middle\n");
	char	*cmd;
	char	**split_cmd;

	(void)i;
	split_cmd = ft_split(av[3], ' ');
	if (dup2(pipefd[0][0], STDIN_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
	if (dup2(pipefd[1][1], STDOUT_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
	for (int k = 0; k < ac - 4; k++)
	{
		close(pipefd[k][0]); // lecture
		close(pipefd[k][1]); // écriture
	}
	close(vars->fd_in);
	close(vars->fd_out);
	cmd = vars->av[1];
	if (!cmd)
		return (free_split(split_cmd), free_all(vars), exit(127));
	execve(cmd, split_cmd, vars->env_cpy);
	perror("execve middle");
	exit(1);
}

void	pipex(t_vars *vars, char **av, int ac)
{
	int	pipefd[ac - 5][2];
    int i;

    i = 0;
    while (i < ac - 4)
    {
        if (pipe(pipefd[i]) < 0)
            return (perror("Pipe"), free_all(vars), exit(1));
        i++;
    }
    i = 1;
	vars->pid[0] = fork();
	if (vars->pid[0] < 0)
		return (perror("Fork"), free_all(vars), exit(1));
	if (vars->pid[0] == 0)
		first_child_process(vars, av, pipefd);
    while (i < ac - 4)
    {
        vars->pid[i] = fork();
        if (vars->pid[i] < 0)
            return (perror("Fork"), free_all(vars), exit(1));
        if (vars->pid[i] == 0)
            middle_child_process(vars, av, pipefd, ac, i);
        else
            ft_printf("Je suis dans le processus Parent\n");
        i++;
    }
	vars->pid[ac - 4] = fork();
	if (vars->pid[ac - 4] < 0)
		return (perror("Fork"), free_all(vars), exit(1));
	if (vars->pid[ac - 4] == 0)
		last_child_process(vars, av, pipefd, ac);
    // close_all_all(vars, pipefd, ac);
	close(vars->fd_in);
	close(vars->fd_out);
	// close(pipefd[0][0]);
	// close(pipefd[0][1]);
	for (int i = 0; i < ac - 4; i++)
	{
		close(pipefd[i][0]); // lecture
		close(pipefd[i][1]); // écriture
	}
    while (wait(NULL) > 0)
        ;
    // free_all(vars);
}

