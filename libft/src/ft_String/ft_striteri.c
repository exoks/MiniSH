/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:20:36 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 18:20:37 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *string, void (*fun)(unsigned int, char *))
{
	int	index;

	index = -1;
	if (string == NULL)
		return ;
	while (string[++index])
		fun(index, string + index);
}
