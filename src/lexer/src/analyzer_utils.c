/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:20:35 by oezzaou           #+#    #+#             */
/*   Updated: 2023/07/28 18:11:58 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyzer.h"

//=== get_current_state =======================================================
int	get_current_state(t_list *token)
{
	int	type;

	type = get_token_type(token);
	if (state_operator(token) == OPERATOR)
		return (OPERATOR);
	if (state_redir(token) == REDIR)
		return (REDIR);
	if (type == CLOSE_PARENTHESIS || type == OPEN_PARENTHESIS)
		return (type);
	if (type == DOUBLE_QUOTES || type == SINGLE_QUOTES)
		return (type);
	if (type == SEMICOLON)
		return (type);
	return (STRING);
}

//=== parse_error =============================================================
int	parse_error(int prev_state, int state, t_list *token, int eq_point)
{
	char	*msg;

	msg = NULL;
	if ((prev_state == START && state == OPERATOR)
		|| (prev_state == OPERATOR && state == OPERATOR)
		|| (prev_state == CLOSE_PARENTHESIS && state == STRING)
		|| (prev_state == OPEN_PARENTHESIS && state == OPERATOR)
		|| (prev_state == OPERATOR && state == CLOSE_PARENTHESIS)
		|| (prev_state == OPEN_PARENTHESIS && state == CLOSE_PARENTHESIS)
		|| (prev_state == CLOSE_PARENTHESIS && state == OPEN_PARENTHESIS)
		|| (prev_state == REDIR && state == REDIR)
		|| (prev_state == REDIR && state == OPERATOR)
		|| (eq_point < 0))
		msg = get_token_name(token);
	if ((prev_state == STRING && state == OPEN_PARENTHESIS)
		|| (!token->next && state == REDIR)
		|| (get_token_type(token) == END))
	{
		msg = get_token_name(token->next);
		if (!msg)
			msg = "newline";
	}
	if (msg != NULL)
		ft_print_error(PARSE_ERROR_MSG"%'\n", msg);
	return (PARSE_ERROR * !(!msg));
}

//=== complete_tokens =========================================================
t_list	*complete_tokens(t_list *token, int eq_point)
{
	int		type;
	t_list	*new_tokens;

	new_tokens = NULL;
	type = get_token_type(token);
	if (type == PIPE || type == AND || type == OR)
		new_tokens = operator_prompt(token);
	if (type == SINGLE_QUOTES || type == DOUBLE_QUOTES)
		new_tokens = quote_prompt(token);
	if (eq_point > 0 && (type == STRING || type == OPEN_PARENTHESIS
			|| type == CLOSE_PARENTHESIS))
		new_tokens = subsh_prompt(token, eq_point);
	return (new_tokens);
}

//=== update_quotes_data ======================================================
void	update_quotes_data(char *buff, int *data)
{
	char	*set;
	int		i;

	set = "'\"";
	i = -1;
	while (buff[++i])
	{
		if (buff[i] == set[-data[TYPE] + 5] && (data[data[TYPE] - 3] % 2 == 0))
			data[TYPE] = -data[TYPE] + 9;
		if (buff[i] == set[0] && data[TYPE] == SINGLE_QUOTES)
			data[SQUOTES]++;
		if (buff[i] == set[1] && data[TYPE] == DOUBLE_QUOTES)
			data[DQUOTES]++;
	}
}
