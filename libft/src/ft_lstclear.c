/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:22:04 by oezzaou           #+#    #+#             */
/*   Updated: 2022/10/02 15:36:31 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//void	ft_del(void *pt);

//====<[ ft_lstclear: ]>========================================================
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*med;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		med = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = med;
	}
	*lst = 0;
}
