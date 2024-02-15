/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:45:11 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 13:45:18 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	index;

	index = -1;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (++index < len)
		*((unsigned char *)dst + index) = *((unsigned char *)src + index);
	return (dst);
}
