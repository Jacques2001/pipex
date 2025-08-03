/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:25 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/03 15:45:52 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_vars	*vars;

	if (ac != 5)
		return (ft_printf("Not enough argument\n"), exit(127), 0);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (0);
	vars_init(vars, av, env);
	vars->path = find_path(env);
	if (!vars->path)
		return (0);
	vars->fd_in = open(av[1], O_RDONLY);
	vars->fd_out = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (vars->fd_in == -1)
		return (ft_printf("File not found\n"), 0);
	if (check_av2(vars->path, av, vars) == 0 || check_av3(vars->path, av,
			vars) == 0)
		return (ft_printf("Command not found\n"), 0);
	pipex(vars, av);
	return (0);
}
