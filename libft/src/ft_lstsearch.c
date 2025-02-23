/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:22:47 by oezzaou           #+#    #+#             */
/*   Updated: 2025/02/23 10:52:29 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsearch(t_list *lst, int (*search)(void *, void *), void *value)
{
	while (lst && search && value)
	{
		if (search(lst->content, value))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
