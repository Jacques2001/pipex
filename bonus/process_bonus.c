#include "../libs/pipex_bonus.h"

void	first_child_process(t_vars *vars, char **av, int (*pipefd)[2])
{
    printf("Je suis dans le premier\n");
	char	*cmd;
	char	**split_cmd;

	split_cmd = ft_split(av[2], ' ');
	if (dup2(vars->fd_in, STDIN_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
	if (dup2(pipefd[0][1], STDOUT_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
    close_all(vars, pipefd[0]);
	cmd = vars->av[2];
	if (!cmd)
		return (free_split(split_cmd), free_all(vars), exit(127));
	if (execve(cmd, split_cmd, vars->env_cpy) < 0)
		return (perror("error"), free_all(vars), exit(1));
}

void	last_child_process(t_vars *vars, char **av, int (*pipefd)[2], int ac)
{
    printf("je suis dans le dernier\n");
	char	*cmd;
	char	**split_cmd;

	split_cmd = ft_split(av[ac - 2], ' ');
	if (dup2(pipefd[ac - 5][0], STDIN_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
	if (dup2(vars->fd_out, STDOUT_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
    close_all(vars, pipefd[ac - 5]);
	cmd = vars->av[ac - 2];
	if (!cmd)
		return (free_split(split_cmd), free_all(vars), exit(127));
	execve(cmd, split_cmd, vars->env_cpy);
	perror("error");
	exit(1);
}

void    middle_child_process(t_vars *vars, char **av, int (*pipefd)[2], int i)
{
    printf("je suis dans le milieux\n");
	char	*cmd;
	char	**split_cmd;

	split_cmd = ft_split(av[i], ' ');
	if (dup2(pipefd[i - 1][0], STDIN_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
	if (dup2(pipefd[i][1], STDOUT_FILENO) < 0)
		return (perror("dup2"), free_split(split_cmd), free_all(vars), exit(1));
    close_all(vars, pipefd[i]);
	cmd = vars->av[i];
	if (!cmd)
		return (free_split(split_cmd), free_all(vars), exit(127));
	execve(cmd, split_cmd, vars->env_cpy);
	perror("error");
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
    i = 0;
    while (i < ac - 4)
    {
        vars->pid[i] = fork();
        if (vars->pid[i] < 0)
            return (perror("Fork"), free_all(vars), exit(1));
    	if (vars->pid[i] == 0 && i == 0)
		    first_child_process(vars, av, pipefd);
        else if (vars->pid[i] == 0 && i == ac - 5)
            last_child_process(vars, av, pipefd, ac);
        else if (vars->pid[i] == 0)
            middle_child_process(vars, av, pipefd, i);
        else
            ft_printf("Je suis dans le processus Parent\n");
        i++;
    }
    close_all_all(vars, pipefd, ac);
    while (wait(NULL) > 0)
        ;
    free_all(vars);
}
