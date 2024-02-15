/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:24:32 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 19:55:38 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *string, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	strlen;

	if (string == NULL)
		return (NULL);
	if (start >= ft_strlen(string))
		return (ft_strdup(""));
	string += start;
	strlen = ft_strlen(string);
	if (len > strlen)
		len = strlen;
	new_string = ft_calloc(len + 1, sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_memmove(new_string, string, len);
	return (new_string);
}
