/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:22:33 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 18:22:35 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *string, char (*fun)(unsigned int, char))
{
	int		index;
	char	*new_string;

	index = -1;
	if (string == NULL)
		return (NULL);
	new_string = ft_calloc(ft_strlen(string) + 1, sizeof(char));
	if (new_string == NULL)
		return (NULL);
	while (string[++index])
		new_string[index] = fun(index, string[index]);
	return (new_string);
}
