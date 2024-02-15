/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:19:20 by hael-mou          #+#    #+#             */
/*   Updated: 2023/06/19 15:08:20 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int character)
{
	if (!string)
		return (NULL);
	while (*string != (char)character)
	{
		if (*string++ == '\0')
			return (0);
	}
	return ((char *)string);
}
