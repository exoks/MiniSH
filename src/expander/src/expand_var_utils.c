/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 05:28:53 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/28 18:41:00 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

//=== extract var =============================================================
char	*extract_var(char *eline, char **line, int in_dquote)
{
	char	*key;
	char	*value;

	*line += 1;
	if (**line == 0 || **line == C_SPACE || **line == '$'
		|| **line == DOUBLE_QUOTE || **line == SINGLE_QUOTE)
	{
		if (**line != DOUBLE_QUOTE && **line != SINGLE_QUOTE)
		{
			(*line) += (**line == '$');
			eline = ft_vstrjoin(2, eline, "$");
		}
		return (eline);
	}
	key = get_var_key(line);
	value = var_value(key);
	if (key == NULL || value == NULL)
		return (free(key), free(value), eline);
	if (in_dquote == FALSE)
	{
		ft_strreplace(value, " \t", C_SPACE);
		ft_strreplace(value, "*", C_STAR);
	}
	return (free(key), ft_strjoin(eline, value));
}

//=== get var key ========================================================
char	*get_var_key(char **line)
{
	int		len;
	char	*key;

	len = (ft_isalpha(**line) || **line == '_');
	if (len == 0 && **line == '?')
		return (++(*line), ft_strdup("?"));
	if (len == 0 && **line != 0)
		return (++(*line), NULL);
	while (ft_isalnum((*line)[len]) || (*line)[len] == '_')
		len++;
	key = ft_substr(*line, 0, len);
	*line += len;
	return (key);
}

//=== get value ===========================================================
char	*var_value(char *key)
{
	char	*value;

	if (key == NULL)
		return (NULL);
	if (*key == '?')
		value = ft_itoa(g_sys.exit_status);
	else
		value = ft_strdup(search_var(g_sys.env, key));
	return (value);
}
