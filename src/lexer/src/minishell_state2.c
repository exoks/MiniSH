/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_state2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:57:40 by hael-mou          #+#    #+#             */
/*   Updated: 2023/06/21 15:04:46 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

//=== state_pipe ========================================
int	state_pipe(char *input)
{
	if (*input == '|' && BONUS == TRUE)
		return (OR);
	return (END);
}

//=== state_redout ======================================
int	state_redout(char *input)
{
	if (*input == '>')
		return (REDIR_APPEND);
	return (END);
}

//=== state_redin =======================================
int	state_redin(char *input)
{
	if (*input == '<')
		return (HERE_DOC);
	return (END);
}

//=== state_operator ====================================
int	state_operator(t_list *token)
{
	int	input;

	input = get_token_type(token);
	if (input == PIPE || input == AND || input == OR)
		return (OPERATOR);
	return (STRING);
}

//=== state_redir ======================================
int	state_redir(t_list *token)
{
	int	input;

	input = get_token_type(token);
	if (input == REDIR_IN
		|| input == REDIR_OUT
		|| input == HERE_DOC
		|| input == REDIR_APPEND)
		return (REDIR);
	return (STRING);
}
