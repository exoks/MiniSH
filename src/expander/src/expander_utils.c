/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:49:51 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/26 17:09:27 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

//=== with single quates ==================================================
char	*with_single_quates(char *eline, char **line)
{
	int	len;

	len = ft_toklen(++(*line), '\'');
	eline = ft_strnjoin(eline, *line, len);
	(*line) += len + 1;
	return (eline);
}

//=== join string =========================================================
char	*join_string(char *eline, char **line, int in_dquote)
{
	*line += in_dquote;
	while (*line != NULL && **line != 0 && **line != DOUBLE_QUOTE
		&& (**line != SINGLE_QUOTE || in_dquote))
	{
		if (**line == '$')
			eline = extract_var(eline, line, in_dquote);
		else
		{
			if (**line == '*' && !in_dquote)
				eline = ft_strnjoin(eline, S_STAR, 1);
			else if (**line == C_SPACE && *(*line + 1) == '~'
				&& !in_dquote)
				eline = home_path(eline, line);
			else
				eline = ft_strnjoin(eline, *line, 1);
			(*line)++;
		}
	}
	*line += in_dquote;
	return (eline);
}

//=============================================
int	is_empty(char *str)
{
	while (str && *str)
	{
		if (*str++ != C_SPACE)
			return (FALSE);
	}
	return (TRUE);
}
