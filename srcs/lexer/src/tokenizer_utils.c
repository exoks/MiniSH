/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:04:53 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/14 19:23:17 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

//=== get_next_state ===========================================================
int	get_next_state(int state, char *input)
{
	int	(*state_func[6])();

	if (*input == '\0' || state == SEMICOLON || state == HERE_DOC
		|| state == AND || state == OR || state == REDIR_APPEND)
		return (END);
	if (state == OPEN_PARENTHESIS || state == CLOSE_PARENTHESIS)
		return (END);
	if (state == AND_IN_FUTURE)
		return (AND);
	state_func[START] = state_start;
	state_func[PIPE] = state_pipe;
	state_func[REDIR_OUT] = state_redout;
	state_func[REDIR_IN] = state_redin;
	state_func[SINGLE_QUOTES] = state_quates;
	state_func[DOUBLE_QUOTES] = state_quates;
	if (state < 6)
		return (state_func[state](input, state));
	return (state_string(input));
}

//=== clean_tokenizer ==========================================================
void	clean_tokenizer(t_list *tokens)
{
	ft_lstclear(&tokens, free_token);
}

//=== set_state ================================================================
void	set_state(t_state *states, int index, char *key, int state)
{
	states[index].key = key;
	states[index].state = state;
}

//=== get_state ================================================================
int	get_state(t_state *states, int size, char input)
{
	int	index;

	index = -1;
	while (++index < size - 1)
	{
		if (ft_strchr(states[index].key, input) != NULL)
			return (states[index].state);
	}
	return (states[index].state);
}
