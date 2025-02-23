/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:20:51 by oezzaou           #+#    #+#             */
/*   Updated: 2023/07/27 17:59:23 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

//=== Lexer ====================================================================
t_list	*lexer(char *line)
{
	t_list	*tokens;

	g_sys.area = LEXER_AREA;
	tokens = tokenizer(line);
	if (!tokens)
		return (NULL);
	if (analyzer(tokens) == NULL)
	{
		g_sys.exit_status = 2;
		return (clean_tokenizer(tokens), NULL);
	}
	return (tokens);
}

//=== tokenizer ================================================================
t_list	*tokenizer(char *line)
{
	int		cur_state;
	int		prv_state;
	t_list	*tokens;
	char	*cursor;

	prv_state = START;
	tokens = NULL;
	while (line != NULL)
	{
		cur_state = get_next_state(prv_state, line);
		if (prv_state == START && cur_state == END)
			break ;
		if (cur_state == END && prv_state != START)
		{
			if (!listadd_token(&tokens, create_token(cursor, line, prv_state)))
				return (NULL);
			prv_state = START;
			continue ;
		}
		if (prv_state == START)
			cursor = line;
		prv_state = cur_state;
		line++;
	}
	return (tokens);
}

//=== analyzer =================================================================
t_list	*analyzer(t_list *tokens)
{
	t_list		*cursor;
	int			cur_state;
	int			prev_state;
	int			eq_point;

	eq_point = 0;
	cursor = tokens;
	prev_state = START;
	while (cursor)
	{
		cur_state = get_current_state(cursor);
		eq_point += (cur_state == OPEN_PARENTHESIS);
		eq_point -= (cur_state == CLOSE_PARENTHESIS);
		if (parse_error(prev_state, cur_state, cursor, eq_point) == PARSE_ERROR)
			return (NULL);
		if (cursor->next == NULL)
			cursor->next = complete_tokens(cursor, eq_point);
		if (!(cursor->next == NULL && eq_point > 0)
			&& get_token_type(cursor) != END)
			cursor = cursor->next;
		prev_state = cur_state;
	}
	return (tokens);
}
