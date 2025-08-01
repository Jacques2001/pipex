/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:33:49 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/23 14:06:49 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (ptr != NULL)
	{
		if (ptr->next == NULL)
		{
			ptr->next = new;
			return ;
		}
		ptr = ptr->next;
	}
}
