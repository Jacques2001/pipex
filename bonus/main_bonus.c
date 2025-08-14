/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:15:53 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/14 11:27:25 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_vars	*vars;

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
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		heredoc(vars, &ac, &av);
	else
	{
		vars->fd_in = open(av[1], O_RDONLY);
		if (vars->fd_in == -1)
			return (ft_printf("File not found\n"), free_all(vars), 0);
	}
	vars->fd_out = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	check_cmd(vars, av);
	return (pipex(vars, av), 0);
}
