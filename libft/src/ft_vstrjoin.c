/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:20:58 by hael-mou          #+#    #+#             */
/*   Updated: 2025/02/23 10:30:19 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_vstrjoin(int nstr, char *dst, ...)
{
	char	*new_string;
	va_list	list;
	va_list	copy;
	char	index;
	size_t	len;

	index = 0;
	len = ft_strlen(dst);
	va_start(list, dst);
	va_copy(copy, list);
	while (++index < nstr)
		len += ft_strlen(va_arg(copy, char *));
	new_string = ft_calloc(len + 1, sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_strlcat(new_string, dst, len + 1);
	while (--index > 0)
		ft_strlcat(new_string, va_arg(list, char *), len + 1);
	va_end(list);
	va_end(copy);
	return (free(dst), new_string);
}
