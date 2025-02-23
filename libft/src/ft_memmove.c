/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:22:06 by oezzaou           #+#    #+#             */
/*   Updated: 2022/10/02 19:26:58 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//====<[ ft_memmove: ]>=========================================================
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src >= dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (--len >= 0 && len <= 2147483647)
			*((char *)dst + len) = *((char *)src + len);
	}
	return (dst);
}
