/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:23:56 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 18:23:57 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char const *string, char delim)
{
	int		wordlen;
	char	*first_word;

	wordlen = 0;
	while (string[wordlen] && string[wordlen] != delim)
		wordlen++;
	first_word = ft_calloc(wordlen + 1, sizeof(char));
	if (first_word == NULL)
		return (NULL);
	ft_memmove(first_word, string, wordlen);
	return (first_word);
}
