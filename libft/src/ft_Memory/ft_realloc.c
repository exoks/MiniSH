/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:19:23 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 14:40:36 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*buffer;

	buffer = ft_calloc(size, sizeof(char));
	if (ptr != NULL && buffer != NULL)
		ft_memmove(buffer, ptr, size);
	return (buffer);
}
