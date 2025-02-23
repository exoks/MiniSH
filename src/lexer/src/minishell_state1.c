/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_state1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:57:40 by hael-mou          #+#    #+#             */
/*   Updated: 2023/06/17 23:33:39 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

//=== state_start =======================================================
int	state_start(char *input)
{
	t_state	state_table[10];
	int		size;

	size = 0;
	set_state(state_table, size++, "|", PIPE);
	set_state(state_table, size++, " \t", START);
	set_state(state_table, size++, ">", REDIR_OUT);
	set_state(state_table, size++, "<", REDIR_IN);
	set_state(state_table, size++, "\"", DOUBLE_QUOTES);
	set_state(state_table, size++, "'", SINGLE_QUOTES);
	if (BONUS == TRUE)
	{
		set_state(state_table, size++, "(", OPEN_PARENTHESIS);
		set_state(state_table, size++, ")", CLOSE_PARENTHESIS);
		set_state(state_table, size++, ";", SEMICOLON);
		if (*input == '&' && *(input + 1) == '&')
			return (AND_IN_FUTURE);
	}
	set_state(state_table, size++, OTHER, STRING);
	return (get_state(state_table, size, *input));
}

//=== state_string ======================================================
int	state_string(char *input)
{
	t_state	state_table[4];

	if (BONUS == TRUE)
	{
		set_state(state_table, 0, "\t |<>();", END);
		if (*input == '&' && *(input + 1) == '&')
			return (END);
	}
	else
	{
		set_state(state_table, 0, "\t |<>", END);
	}
	set_state(state_table, 1, "\"", DOUBLE_QUOTES);
	set_state(state_table, 2, "'", SINGLE_QUOTES);
	set_state(state_table, 3, OTHER, STRING);
	return (get_state(state_table, 4, *input));
}

//=== state_quates ======================================================
int	state_quates(char *input, int prv_state)
{
	t_state	state_table[2];
	char	*quate;

	quate = NULL;
	if (prv_state == DOUBLE_QUOTES)
	{
		quate = "\"";
	}
	else if (prv_state == SINGLE_QUOTES)
	{
		quate = "'";
	}
	set_state(state_table, 0, quate, STRING);
	set_state(state_table, 1, OTHER, prv_state);
	return (get_state(state_table, 2, *input));
}
