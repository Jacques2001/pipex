/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:33:59 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 13:58:32 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while ((*lst) != NULL)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = tmp;
	}
	(*lst) = NULL;
}
