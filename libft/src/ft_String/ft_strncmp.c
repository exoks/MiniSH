/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:22:54 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 21:02:05 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && string1[i] != '\0' && string2[i] != '\0'
		&& ((unsigned char *)string1)[i] == ((unsigned char *)string2)[i])
		i++;
	return (((unsigned char *)string1)[i] - ((unsigned char *)string2)[i]);
}
