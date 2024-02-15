/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:08:37 by hael-mou          #+#    #+#             */
/*   Updated: 2023/06/15 17:16:10 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreplace(char *str, char *c1, char c2)
{
	int	index;

	while (str != NULL && *str != 0)
	{
		index = -1;
		while (c1[++index] != 0)
		{
			if (*str == c1[index])
				*str = c2;
		}
		str++;
	}
}
