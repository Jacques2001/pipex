#include "../libs/pipex_bonus.h"

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

void    child1_support(t_vars *vars, char **split_cmd)
{
	if (vars->fd_in >= 0)
    {
		if (dup2(vars->fd_in, STDIN_FILENO) < 0)
            return (perror("error"), free_split(split_cmd),
			    free_all(vars), exit(1));
    }
	else
	{
		vars->fd_null = open("/dev/null", O_RDONLY);
        if (vars->fd_null == -1)
            return (perror("error"), free_split(split_cmd),
			    free_all(vars), exit(1));
		if (dup2(vars->fd_null, STDIN_FILENO) < 0)
            return (perror("error"), free_split(split_cmd),
			    free_all(vars), exit(1));
		close(vars->fd_null);
	}
}
