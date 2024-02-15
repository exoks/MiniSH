/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:19:50 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 18:20:08 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcout(char const *string, char delim)
{
	int	count;

	count = 0;
	while (*string)
	{
		while (*string && *string == delim)
			string++;
		if (*string)
			count++;
		while (*string && *string != delim)
			string++;
	}
	return (count);
}
