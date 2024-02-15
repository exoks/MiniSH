/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:59:10 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 22:42:07 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	isendline(char *str)
{
	while (str && *str)
	{
		if (*str == '\n')
			return (YES);
		str++;
	}
	return (NO);
}

char	*gnl_realloc(char *str, size_t size, int *oldlen, char free_str)
{
	char	*newstr;
	int		i;

	*oldlen = 0;
	i = 0;
	while (str && str[*oldlen])
		(*oldlen)++;
	newstr = (char *)malloc(*oldlen + size + 1);
	if (!newstr)
	{
		free (str);
		return (NULL);
	}
	while (str && str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = 0;
	if (free_str == YES)
		free (str);
	return (newstr);
}
