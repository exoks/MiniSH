/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:09:10 by oezzaou           #+#    #+#             */
/*   Updated: 2022/09/30 12:18:53 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//====<[ ft_word_counter: ]>====================================================
static int	ft_word_counter(char const *s, char c)
{
	int	i;
	int	counter;

	counter = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			counter++;
	}
	return (counter);
}

//====<[ ft_strsize: ]>=========================================================
static int	ft_strsize(char const *s, char c)
{
	if (*s && *s != c)
		return (1 + ft_strsize(++s, c));
	return (0);
}

//====<[ ft_str_cpy: ]>=========================================================
static int	ft_str_cpy(char *dst, char const *src, char c)
{
	int	i;

	i = -1;
	while (src[++i] && src[i] != c)
		dst[i] = src[i];
	dst[i] = 0;
	return (i);
}

//====<[ ft_split: ]>===========================================================
char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;

	k = 0;
	if (!s)
		return (0);
	tab = (char **) malloc ((ft_word_counter(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			tab[k] = (char *) malloc((ft_strsize(&s[i], c) + 1) * sizeof(char));
			i += ft_str_cpy(tab[k], &s[i], c);
			k++;
		}
	}
	tab[k] = 0;
	return (tab);
}
