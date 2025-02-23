/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:35:31 by oezzaou           #+#    #+#             */
/*   Updated: 2022/10/23 12:18:23 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

//====<[ ft_lstnew: ]>==========================================================
t_buff	*ft_lstnew(char *buff)
{
	t_buff	*node;

	node = (t_buff *) malloc(sizeof(t_buff));
	if (!node)
		return (0);
	node->buff = buff;
	node->next = 0;
	return (node);
}

//====<[ ft_lstlast: ]>=========================================================
t_buff	*ft_lstlast(t_buff *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

//====<[ ft_lstclear: ]>========================================================
t_buff	*ft_lstclear(t_buff **head)
{
	t_buff	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free((*head)->buff);
		free(*head);
		*head = tmp;
	}
	head = 0;
	return (0);
}

//====<[ ft_strcat: ]>==========================================================
char	*ft_strcat(char *dst, char *src)
{
	int	i;

	i = -1;
	while (dst[++i])
		;
	while (*src)
		dst[i++] = *(src++);
	dst[i] = 0;
	return (dst);
}
