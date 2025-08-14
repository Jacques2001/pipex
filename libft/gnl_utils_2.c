/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:04:06 by jchiu             #+#    #+#             */
/*   Updated: 2025/08/14 11:11:10 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_last_gnl(int free_flag, char *stash)
{
	if (free_flag)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
	}
	return (NULL);
}
