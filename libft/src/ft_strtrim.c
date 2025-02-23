/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:08:31 by oezzaou           #+#    #+#             */
/*   Updated: 2022/09/30 12:08:34 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//====<[ ft_strtrim: ]>=========================================================
char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	if (!s1 || !set)
		return (0);
	i = -1;
	while (s1[++i] && ft_strchr(set, s1[i]))
		;
	j = i + ft_strlen(&s1[i]);
	while (j && ft_strchr(set, s1[j]))
		j--;
	if (j - i < 0)
		j = 0;
	else
		j = j - i + 1;
	return (ft_substr(s1, i, j));
}
