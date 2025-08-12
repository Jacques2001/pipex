/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:15:56 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/12 18:15:57 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

char	**give_slash(char **path)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc((count_args(path) + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < count_args(path) + 1)
		copy[i++] = NULL;
	i = 0;
	while (path[i])
	{
		copy[i] = ft_strjoin(path[i], "/");
		if (!copy[i])
			return (free_split(copy), NULL);
		i++;
	}
	free_split(path);
	return (copy);
}

int	check_av(char **path, char *str, t_vars *vars)
{
	int		i;
	char	*joined;
	char	**split;

	i = 0;
	if (!str)
		return (1);
	split = ft_split(str, ' ');
	if (!split)
		return (0);
	while (path[i])
	{
		joined = ft_strjoin(path[i], split[0]);
		if (access(joined, X_OK) == 0)
			return (free_split(split), vars->av[vars->av_i++] = joined, 1);
		free(joined);
		joined = NULL;
		i++;
	}
	free_split(split);
	return (0);
}

char	**find_path(char **env)
{
	int		i;
	char	**path;
	char	**copy;
	char	**env_cpy;

	i = 0;
	path = NULL;
	env_cpy = malloc((count_args(env) + 1) * sizeof(char *));
	if (!env_cpy)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			env_cpy[i] = ft_substr(env[i], 5, ft_strlen(env[i]));
			if (!env_cpy[i])
				return (NULL);
			path = ft_split(env_cpy[i], ':');
			free(env_cpy[i]);
			break ;
		}
		i++;
	}
	return (free(env_cpy), copy = give_slash(path), copy);
}

void	vars_init(t_vars *vars, char **av, char **env, int ac)
{
	int	i;

	i = 0;
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
