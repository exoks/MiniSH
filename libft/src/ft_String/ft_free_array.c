/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:44:15 by hael-mou          #+#    #+#             */
/*   Updated: 2023/06/25 11:47:25 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **node)
{
	int	index;

	index = 0;
	while (node != NULL && node[index])
	{
		free(node[index++]);
	}
	free(node);
}
