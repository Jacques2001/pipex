#include "../libs/pipex_bonus.h"

int	is_empty_cmd(int ac, char **av)
{
	int i;

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
	if (vars->pid)
		free(vars->pid);
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
