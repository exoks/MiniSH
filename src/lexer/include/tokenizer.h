/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 07:37:55 by hael-mou          #+#    #+#             */
/*   Updated: 2023/06/24 21:44:51 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

/*###############################################################
#  	   * Includes :		    								 	#
###############################################################*/
# include "libft.h"
# include "token.h"

/*###############################################################
#  	   * define :		    								 	#
###############################################################*/
# define AND_IN_FUTURE 22
# ifndef BONUS
#  define BONUS 1
# endif

/*###############################################################
#  	   * types :		    								 	#
###############################################################*/
typedef struct s_state
{
	char	*key;
	int		state;
}	t_state;

/*###############################################################
#  	   * Functions :											#
###############################################################*/
// minishell toknizer
t_list	*tokenizer(char *line);

// state utils 1:
int		state_start(char *input);
int		state_string(char *input);
int		state_quates(char *input, int prv_state);

// state utils 2:
int		state_pipe(char *input);
int		state_redout(char *input);
int		state_redin(char *input);

// tokenizer utils:
int		get_next_state(int state, char *input);
void	set_state(t_state *states, int index, char *key, int state);
int		get_state(t_state *states, int size, char input);
void	clean_tokenizer(t_list *tokens);

#endif /* TOKENIZER_H */
