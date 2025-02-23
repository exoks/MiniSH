/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:20:58 by hael-mou          #+#    #+#             */
/*   Updated: 2025/02/23 10:41:41 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *string1, char const *string2, size_t n)
{
	char	*new_string;
	size_t	strlen1;
	size_t	strlen2;

	if (string1 == NULL || string2 == NULL)
		return (NULL);
	strlen1 = ft_strlen(string1);
	strlen2 = ft_strlen(string2);
	if (strlen2 > n)
		strlen2 = n;
	new_string = ft_calloc(strlen1 + strlen2 + 1, sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_memmove(new_string, string1, strlen1);
	ft_memmove(new_string + strlen1, string2, strlen2);
	return (free(string1), new_string);
}
