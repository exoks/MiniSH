/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:24:14 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 18:24:15 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char character, char const *sep)
{
	while (*sep)
	{
		if (character == *sep)
			return (1);
		sep++;
	}
	return (0);
}

char	*ft_strtrim(char const *string, char const *set)
{
	size_t	len;
	char	*new_string;

	if (string == NULL)
		return (NULL);
	while (check(*string, set))
		string++;
	if (*string == '\0')
		return (ft_strdup(""));
	len = ft_strlen(string);
	while (check(string[len - 1], set))
		len--;
	new_string = ft_calloc(len + 1, sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_memmove(new_string, string, len);
	return (new_string);
}
