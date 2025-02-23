/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:21:54 by oezzaou           #+#    #+#             */
/*   Updated: 2023/07/27 14:44:52 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYZER_H
# define ANALYZER_H

/*###############################################################
#  	   * Includes :		    								 	#
###############################################################*/
# include <stdio.h>
# include <readline/readline.h>
# include "libft.h"
# include "token.h"

/*###############################################################
#  	   * Define :		    								 	#
###############################################################*/
# define PARSE_ERROR_MSG "minishell: syntax error near unexpected token `"
# define PARSE_ERROR	 258

/*###############################################################
#  	   * Prompts :		    								 	#
###############################################################*/
# define SUBSH_PROMPT		"subsh> "
# define PIPE_PROMPT		"pipe> "
# define AND_PROMPT			"cmdand> "
# define OR_PROMPT			"cmdor> "
# define QUOTE_PROMPT		"quote> "
# define DQUOTE_PROMPT		"dquote> "

/*###############################################################
#  	   * Typedef :		    								 	#
###############################################################*/
typedef enum e_data
{
	TYPE,
	SQUOTES,
	DQUOTES
}			t_data;

/*###############################################################
#  	   * Functions :		   								 	#
###############################################################*/
// Analyzer:
t_list	*analyzer(t_list *tokens);
int		parse_error(int prev_state, int state, t_list *token, int eq_point);
t_list	*complete_tokens(t_list *token, int eq_point);
void	update_quotes_data(char *buff, int *data);

// minishell toknizer
t_list	*tokenizer(char *line);
void	clean_tokenizer(t_list *tokens);

// Subtokens:
t_list	*subsh_prompt(t_list *token, int eq_point);
t_list	*operator_prompt(t_list *token);
t_list	*quote_prompt(t_list *token);
char	*get_prompt(int type);

// STATES :

int		get_current_state(t_list *token);
int		state_operator(t_list *token);
int		state_redir(t_list *token);

#endif /* ANALYZER_H */
