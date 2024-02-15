/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:22:47 by oezzaou           #+#    #+#             */
/*   Updated: 2023/06/17 15:03:21 by hael-mou         ###   ########.fr       */
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
