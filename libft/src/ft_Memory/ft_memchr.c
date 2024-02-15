/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:50:10 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 13:50:18 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memory, int c, size_t len)
{
	size_t	index;

	index = -1;
	while (++index < len)
	{
		if (*((unsigned char *)memory + index) == (unsigned char)c)
			return ((void *)memory + index);
	}
	return (NULL);
}
