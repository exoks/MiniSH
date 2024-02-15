/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:22:04 by oezzaou           #+#    #+#             */
/*   Updated: 2023/06/12 17:29:38 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*med;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		med = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = med;
	}
	lst = NULL;
}
