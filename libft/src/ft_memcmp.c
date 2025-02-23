/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:32:30 by oezzaou           #+#    #+#             */
/*   Updated: 2022/10/02 20:29:41 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//====<[ ft_memcmp: ]>==========================================================
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;

	str1 = (unsigned char *) s1;
	i = 0;
	while (i < n && str1[i] == *((unsigned char *)s2 + i))
		i++;
	if (i != n)
		return (str1[i] - *((unsigned char *)s2 + i));
	return (0);
}
