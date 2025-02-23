/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:44:15 by hael-mou          #+#    #+#             */
/*   Updated: 2025/02/23 10:46:50 by oezzaou          ###   ########.fr       */
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
