#include "../libs/pipex.h"

void child1_process(t_vars *vars, char **av, int *fd)
{
    char *cmd;
    char **split_cmd;

    // printf("%s\n", vars->av2);
    split_cmd = ft_split(av[2], ' ');
    for (int i = 0; split_cmd[i]; i++)
        printf("fefeWWFEF%s\n", split_cmd[i]);
    // if (dup2(vars->fd_in, 0) == -1)
    //     return (perror("dup2"));
    dup2(vars->fd_in, STDIN_FILENO);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(vars->fd_in);
    close(fd[1]);
    close(vars->fd_out);
    cmd = vars->av2;
    if (!cmd)
        return ;
    execve(cmd, split_cmd, vars->env_cpy);
    perror("error");
    free(cmd);
    exit(127);
}

void    child2_process(t_vars *vars, char **av, int *fd)
{
    char *cmd;
    char **split_cmd;

    split_cmd = ft_split(av[3], ' ');
    for (int i = 0; split_cmd[i]; i++)
        printf("fefeWWFEF%s\n", split_cmd[i]);
    dup2(fd[0], STDIN_FILENO);
    dup2(vars->fd_out, STDOUT_FILENO);
    close(fd[0]);
    close(vars->fd_in);
    close(fd[1]);
    close(vars->fd_out);
    cmd = vars->av3;
    if (!cmd)
        return ;
    // printf("%s\n", cmd);
    execve(cmd, split_cmd, vars->env_cpy);
    perror("error");
    free(cmd);
    exit(127);
}

void    pipex(t_vars *vars, char **av)
{
    int   fd[2];  
    
    pipe(fd);
    vars->pid_1 = fork();
    if (vars->pid_1 < 0)
         return (perror("Fork"));
    if (vars->pid_1 == 0)
        child1_process(vars, av, fd);
    vars->pid_2 = fork();
    if (vars->pid_2 < 0)
        return (perror("Fork"));
    if (vars->pid_2 == 0)
        child2_process(vars, av, fd);
    close(vars->fd_in);
    close(vars->fd_out);
    close(fd[0]);
    close(fd[1]);
    waitpid(vars->pid_1, NULL, 0);
    waitpid(vars->pid_2, NULL, 0);
}
