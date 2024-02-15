/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 05:28:53 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/28 18:05:38 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

//=== expand line : ===========================================================
char	**expand_line(char *line)
{
	char	**exp_line;
	char	**tmp;

	exp_line = expand_var(line);
	if (exp_line && *exp_line && **exp_line != 0)
	{
		tmp = exp_line;
		exp_line = expand_wildcard(tmp);
		ft_free_array(tmp);
	}
	return (exp_line);
}

//=== expand var : ============================================================
char	**expand_var(char *line)
{
	char	**exp_line;
	char	*e_tmp;
	int		q_str;

	q_str = FALSE;
	e_tmp = ft_strdup("");
	while (line != NULL && *line != 0)
	{
		if (*line == SINGLE_QUOTE && ++q_str)
			e_tmp = with_single_quates(e_tmp, &line);
		else if (*line == DOUBLE_QUOTE && ++q_str)
			e_tmp = join_string(e_tmp, &line, TRUE);
		else
			e_tmp = join_string(e_tmp, &line, FALSE);
	}
	if (is_empty(e_tmp) && *e_tmp != C_SPACE && q_str)
	{
		exp_line = ft_split("\1", C_SPACE);
		ft_strreplace(*exp_line, "\1", '\0');
		return (free(e_tmp), exp_line);
	}
	exp_line = ft_split(e_tmp, C_SPACE);
	return (free(e_tmp), exp_line);
}

//=== expand wildcard : =======================================================
char	**expand_wildcard(char **arg)
{
	char	**exp_line;
	char	*tmp;

	tmp = ft_strdup("");
	while (arg && *arg)
	{
		if (ft_strchr(*arg, C_STAR) == NULL)
			tmp = ft_vstrjoin(3, tmp, *arg, S_SPACE);
		else
			tmp = ft_strjoin(tmp, extract_star(*arg));
		arg++;
	}
	exp_line = ft_split(tmp, C_SPACE);
	return (free(tmp), exp_line);
}

//=== expand heredoc ==========================================================
char	*expand_heredoc(char *line)
{
	char	*exp_line;
	char	*save;

	save = line;
	exp_line = ft_strdup("");
	while (line != NULL && *line != 0)
	{
		if (*line == '$' && *(line + 1) != '"' && *(line + 1) != '\''
			&& *(line + 1) != '\n' && *(line + 1) != 0)
			exp_line = extract_var(exp_line, &line, TRUE);
		else
			exp_line = ft_strnjoin(exp_line, line++, 1);
	}
	return (free(save), exp_line);
}
