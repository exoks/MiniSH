/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrmif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:09:51 by hael-mou          #+#    #+#             */
/*   Updated: 2025/02/23 10:31:53 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrmif(t_list **list, void *ref, int (*cmp)(), void (*del)(void *))
{
	t_list		*current;
	t_list		*previous;
	t_list		*delnode;

	if (!list || !ref || !cmp || !del)
		return ;
	delnode = NULL;
	previous = NULL;
	current = *list;
	while (current)
	{
		if (cmp(current->content, ref) == TRUE)
		{
			if (previous == NULL)
				*list = current->next;
			else
				previous->next = current->next;
			delnode = current;
			current = current->next;
			ft_lstdelone(delnode, del);
			continue ;
		}
		previous = current;
		current = current->next;
	}
}
