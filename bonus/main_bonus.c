/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:25 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/09 12:30:51 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars_init(vars, av, env);
	vars->path = find_path(env);
	if (!vars->path)
		return (free_all(vars), 1);
	vars->fd_in = open(av[1], O_RDONLY);
	vars->fd_out = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (vars->fd_in == -1)
		return (ft_printf("File not found\n"), free_all(vars), 127);
	if (check_av2(vars->path, av, vars) == 0 || check_av3(vars->path, av,
			vars) == 0)
		return (ft_printf("Command not found\n"), free_all(vars), 127);
	if (pipex(vars, av, ac) == 1)
		return (127);
	return (0);
}
