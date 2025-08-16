/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:15:56 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/16 17:19:42 by jchiu            ###   ########.fr       */
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
		return (free_split(path), NULL);
	while (i < count_args(path) + 1)
		copy[i++] = NULL;
	i = 0;
	while (path[i])
	{
		copy[i] = ft_strjoin(path[i], "/");
		if (!copy[i])
			return (free_split(copy), free_split(path), NULL);
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
		if (ft_strncmp(path[i], split[0], ft_strlen(path[i])) == 0)
			return (joined = ft_strdup(split[0]), free_split(split),
				vars->av[vars->av_i++] = joined, 1);
		joined = ft_strjoin(path[i], split[0]);
		if (!joined)
			return (free_split(split), free_all(vars), exit(1), 1);
		if (access(joined, X_OK) == 0)
			return (free_split(split), vars->av[vars->av_i++] = joined, 1);
		free(joined);
		joined = NULL;
		i++;
	}
	return (free_split(split), vars->av[vars->av_i++] = ft_strdup(""), 0);
}

char	**find_path(char **env)
{
	int		i;
	char	**path;
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
				return (free(env_cpy), NULL);
			path = ft_split(env_cpy[i], ':');
			if (!path)
				return (free(env_cpy[i]), free(env_cpy), NULL);
			free(env_cpy[i]);
			break ;
		}
		i++;
	}
	return (free(env_cpy), give_slash(path));
}

int	is_empty_cmd(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac - 1)
	{
		if (!av[i] || !av[i][0])
			return (1);
		i++;
	}
	return (0);
}

void	check_cmd(t_vars *vars, char **av)
{
	int	i;

	i = 2;
	while (i < vars->ac - 2)
	{
		if (check_av(vars->path, av[i], vars) == 0)
			ft_printf("error: Command not found: %s\n", av[i]);
		i++;
	}
	if (check_av(vars->path, av[vars->ac - 2], vars) == 0)
	{
		ft_printf("error: Command not found: %s\n", av[vars->ac - 2]);
		free_all(vars);
		exit(127);
	}
}
