/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:00:04 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 20:15:26 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int character)
{
	if (character == '\t' || character == ' ')
		return (TRUE);
	if (character == '\v' || character == '\f')
		return (TRUE);
	if (character == '\n' || character == '\r')
		return (TRUE);
	return (FALSE);
}
