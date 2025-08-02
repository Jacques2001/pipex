#include "../libs/pipex.h"

void give_slash(char **path)
{
    int i;

    i = 0;
    while (path[i])
    {
        path[i] = ft_strjoin(path[i], "/");
        if (!path[i])
            return ;
        i++;
    }
}
int check_av2(char **path, char **av, t_vars *vars)
{
    int i;
    char *joined;
    char **split;

    i = 0;
    split = ft_split(av[2], ' ');
    while (path[i])
    {
        joined = ft_strjoin(path[i], split[0]);
        if (access(joined, X_OK) == 0)
            return (vars->av2 = joined, 1);
        free(joined);
        joined = NULL;
        i++;
    }
    return 0;
}

int check_av3(char **path, char **av, t_vars *vars)
{
    int i;
    char *joined;
    char **split;

    i = 0;
    split = ft_split(av[3], ' ');
    while (path[i])
    {
        joined = ft_strjoin(path[i], split[0]);
        if (access(joined, X_OK) == 0)
            return (vars->av3 = joined, 1);
        free(joined);
        joined = NULL;
        i++;
    }
    return 0;
}

char    **find_path(char **env)
{
    int i;
    char **path;

    i = 0;
    path = NULL;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
        {
            env[i] = ft_substr(env[i], 5, ft_strlen(env[i]));
            path = ft_split(env[i], ':');
            if (!path)
                return NULL;
            break;
        }
        i++;
    }
    give_slash(path);
    return path;
}

void    vars_init(t_vars *vars, char **av, char **env)
{
    vars->fd_in = 0;
    vars->fd_out = 0;
    vars->path = NULL;
    // vars->pid_1 = 0;
    // vars->pid_2 = 0;
    vars->env_cpy = env;
    vars->av_cpy = av;
    vars->av2 = NULL;
    vars->av3 = NULL;
}
