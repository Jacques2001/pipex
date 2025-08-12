/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:15:53 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/12 18:15:54 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_vars	*vars;
	int		i;

	i = 2;
	if (is_empty_cmd(ac, av) == 1)
		return (ft_printf("Command not found\n"), 1);
	if (ac < 5)
		return (ft_printf("Not enough argument\n"), exit(1), 127);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars_init(vars, av, env, ac);
	vars->path = find_path(env);
	if (!vars->path)
		return (free_all(vars), 1);
	vars->fd_in = open(av[1], O_RDONLY);
	vars->fd_out = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (vars->fd_in == -1)
		return (ft_printf("File not found\n"), free_all(vars), 0);
	while (i < ac - 1)
	{
		if (check_av(vars->path, av[i++], vars) == 0)
			return (ft_printf("Command not found\n"), free_all(vars), 127);
	}
	return (pipex(vars, av, ac), 0);
}
