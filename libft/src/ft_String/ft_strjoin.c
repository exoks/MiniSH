/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:20:58 by hael-mou          #+#    #+#             */
/*   Updated: 2023/06/20 19:36:56 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *string1, char const *string2)
{
	char	*new_string;
	size_t	strlen1;
	size_t	strlen2;

	if (string1 == NULL || string2 == NULL)
		return (NULL);
	strlen1 = ft_strlen(string1);
	strlen2 = ft_strlen(string2);
	new_string = ft_calloc(strlen1 + strlen2 + 1, sizeof(char));
	if (!new_string)
		return (NULL);
	ft_memcpy(new_string, string1, strlen1);
	ft_memmove(new_string + strlen1, string2, strlen2 + 1);
	free(string1);
	free((void *) string2);
	return (new_string);
}
