/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:26:16 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/09 21:04:00 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrnchr(int *array, int number, int len)
{
	int	index;

	index = -1;
	while (++index < len)
		if (array[index] == number)
			return (TRUE);
	return (FALSE);
}
