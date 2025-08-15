/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:29 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/15 13:09:31 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex.h"

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

int	check_av2(char **path, char **av, t_vars *vars)
{
	int		i;
	char	*joined;
	char	**split;

	i = 0;
	if (!av[2])
		return (1);
	split = ft_split(av[2], ' ');
	if (!split)
		return (0);
	while (path[i])
	{
		if (ft_strncmp(path[i], split[0], ft_strlen(path[i])) == 0)
		{
			joined = ft_strdup(split[0]);
			return (free_split(split), vars->av2 = joined, 1);	 
		}
		joined = ft_strjoin(path[i], split[0]);
		if (access(joined, X_OK) == 0)
			return (free_split(split), vars->av2 = joined, 1);
		free(joined);
		joined = NULL;
		i++;
	}
	return (free_split(split), 0);
}

int	check_av3(char **path, char **av, t_vars *vars)
{
	int		i;
	char	*joined;
	char	**split;

	i = 0;
	if (!av[3])
		return (1);
	split = ft_split(av[3], ' ');
	if (!split)
		return (0);
	while (path[i])
	{
		if (ft_strncmp(path[i], split[0], ft_strlen(path[i])) == 0)
		{
			joined = ft_strdup(split[0]);
			return (free_split(split), vars->av3 = joined, 1);	 
		}
		joined = ft_strjoin(path[i], split[0]);
		if (access(joined, X_OK) == 0)
			return (free_split(split), vars->av3 = joined, 1);
		free(joined);
		joined = NULL;
		i++;
	}
	return (free_split(split), 0);
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

void	vars_init(t_vars *vars, char **av, char **env)
{
	vars->fd_in = 0;
	vars->fd_out = 0;
	vars->path = NULL;
	vars->pid_1 = 0;
	vars->pid_2 = 0;
	vars->env_cpy = env;
	vars->av_cpy = av;
	vars->av2 = NULL;
	vars->av3 = NULL;
}
