/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:23:10 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 21:10:06 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (j < len && haystack[j])
	{
		i = 0;
		while (needle[i])
		{
			if (needle[i] != haystack[j + i] || !(j + i < len))
				break ;
			i++;
		}
		if (!needle[i])
			return ((char *)haystack + j);
		j++;
	}
	return (NULL);
}
