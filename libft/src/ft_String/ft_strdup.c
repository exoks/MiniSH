/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:20:19 by hael-mou          #+#    #+#             */
/*   Updated: 2023/06/12 12:34:29 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*new_string;
	size_t	len;

	if (string == NULL)
		return (NULL);
	len = ft_strlen(string) + 1;
	new_string = malloc(len);
	if (new_string == NULL)
		return (NULL);
	ft_memmove(new_string, string, len);
	return (new_string);
}
