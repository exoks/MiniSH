/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:28:58 by oezzaou           #+#    #+#             */
/*   Updated: 2022/10/02 20:31:10 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//====<[ ft_strnstr: ]>=========================================================
char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if (haystack == 0 && n == 0)
		return (0);
	if (needle[0] == 0)
		return ((char *) haystack);
	i = 0;
	while (haystack[i] && i < n)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && i + j < n)
			j++;
		if (j == ft_strlen(needle))
			return ((char *) &haystack[i]);
		i++;
	}
	return (0);
}
