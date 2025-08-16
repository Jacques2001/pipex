/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:33:25 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/16 13:54:38 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_vars	*vars;

	if (!env || !env[0])
		return (1);
	if (is_empty_cmd(av[2]) == 1 || is_empty_cmd(av[3]) == 1)
		return (ft_printf("Command not found\n"), 1);
	if (ac != 5)
		return (ft_printf("Arguments not valid\n"), exit(1), 127);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars_init(vars, av, env);
	vars->path = find_path(env);
	if (!vars->path)
		return (free_all(vars), 1);
	vars->fd_in = open(av[1], O_RDONLY);
	vars->fd_out = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (vars->fd_in == -1)
		perror("error");
	if (check_av2(vars->path, av, vars) == 0)
		ft_printf("error: Command not found: %s\n", av[2]);
	if (check_av3(vars->path, av, vars) == 0)
		return (ft_printf("error: Command not found: %s\n", av[3]),
			free_all(vars), 127);
	return (pipex(vars, av), 0);
}
