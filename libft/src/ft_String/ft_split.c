/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:19:06 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/24 22:21:45 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **words)
{
	int	index;

	index = 0;
	while (words[index])
		free(words[index++]);
	free(words);
}

char	**ft_split(char const *string, char delim)
{
	int		count_numbers;
	char	**words;
	int		index;

	if (!string)
		return (NULL);
	index = 0;
	count_numbers = ft_strcout(string, delim);
	words = ft_calloc(count_numbers + 1, sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (*string)
	{
		while (*string && *string == delim)
			string++;
		if (*string)
			words[index++] = ft_strtok(string, delim);
		if (*string && words[index - 1] == NULL)
			return (free_all(words), NULL);
		while (*string && *string != delim)
			string++;
	}
	return (words);
}
