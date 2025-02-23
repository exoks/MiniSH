/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toklen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:56:47 by hael-mou          #+#    #+#             */
/*   Updated: 2025/02/23 10:48:29 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_toklen(const char *string, const char delim)
{
	size_t	len;

	len = 0;
	while (string[len] != '\0' && string[len] != delim)
		len++;
	return (len);
}
