/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:38:15 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/16 16:15:37 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert(char *string, int number, int len)
{
	while (number > 0)
	{
		string[--len] = number % 10 + '0';
		number /= 10;
	}
	return (string);
}

char	*ft_itoa(int number)
{
	char	*string;
	int		len;

	if (number == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (number == 0)
		return (ft_strdup("0"));
	len = ft_nbrlen(number);
	string = ft_calloc(len + 1, sizeof(char));
	if (string == NULL)
		return (NULL);
	if (number < 0)
	{
		number *= -1;
		*string = '-';
	}
	return (convert(string, number, len));
}
