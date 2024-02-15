/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:23:26 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 19:53:57 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int character)
{
	int	len;

	len = ft_strlen(string);
	while (len >= 0)
	{
		if (*((char *)string + len--) == (char)character)
			return ((char *)string + len + 1);
	}
	return (NULL);
}
