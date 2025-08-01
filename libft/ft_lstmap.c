/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiu <jchiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:34:24 by jchiu             #+#    #+#             */
/*   Updated: 2025/04/29 09:51:00 by jchiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_all(t_list *plan, void (*del)(void *))
{
	t_list	*tmp;

	while (plan != NULL)
	{
		tmp = plan->next;
		del(plan->content);
		free(plan);
		plan = tmp;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*wagon;
	t_list	*plan;
	t_list	*la;

	plan = NULL;
	while (lst != NULL)
	{
		wagon = malloc(sizeof(t_list));
		if (wagon == NULL)
		{
			free_all(plan, del);
			return (NULL);
		}
		wagon->content = f(lst->content);
		wagon->next = NULL;
		if (plan == NULL)
			plan = wagon;
		else
			la->next = wagon;
		la = wagon;
		lst = lst->next;
	}
	return (plan);
}
