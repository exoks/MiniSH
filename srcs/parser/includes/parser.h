/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:23:48 by oezzaou           #+#    #+#             */
/*   Updated: 2023/07/27 18:30:39 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*###############################################################
#		* Includes :		    							 	#
###############################################################*/
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include "readline.h"
# include "tokenizer.h"
# include "defines.h"
# include "types.h"
# include "operator.h"
# include "command.h"
# include "file.h"
# include "pipe.h"
# include "expander.h"

/*###############################################################
#  	   * Functions :											#
###############################################################*/

// Parser :
t_node		*parser(t_list *tokens);
void		clean_tree(t_node *tree);

// Parse tree:
t_node		*parse_seq(t_list **tokens);
t_node		*parse_and_or(t_list **tokens);
t_node		*parse_pipe(t_list **tokens);
t_node		*parse_command(t_list **tokens);
t_node		*parse_subshell(t_list **tokens);

//parse command utils:
t_list		*extract_files(t_list *tokens);
char		*join_argument(t_list *tokens);
int			is_end_of_command(t_list *token);
int			is_redirection(t_list *token);

//heredoc
int			run_heredoc(t_list *file);
void		heardoc_readlines(t_list *file, int fd);
int			remove_quotes(t_list *file);
int			close_iofile_pipe(t_list *file, int c_pipe);

//SIGNAL:
void		minish_sigign(void);
void		minishell_signal(void);

#endif
