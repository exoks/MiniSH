/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:23:35 by oezzaou           #+#    #+#             */
/*   Updated: 2022/10/02 15:40:52 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//====<[ ft_lstmap: ]>==========================================================
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	if (!lst)
		return (0);
	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	head = new;
	head->content = f(lst->content);
	lst = lst->next;
	while (lst)
	{
		head->next = malloc (sizeof(t_list));
		head = head->next;
		if (!head)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		head->content = f(lst->content);
		lst = lst->next;
	}
	head->next = 0;
	return (new);
}
