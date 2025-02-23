/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:23:49 by oezzaou           #+#    #+#             */
/*   Updated: 2025/02/23 20:34:53 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//====<[ ft_strlcat: ]>=========================================================
size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dst_len;
	size_t	src_len;

	if (src == 0 || dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	index = dst_len;
	while (*src && index < dstsize - 1)
		dst[index++] = *(src++);
	dst[index] = 0;
	return (dst_len + src_len);
}
