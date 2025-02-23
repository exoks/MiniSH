/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:17:58 by hael-mou          #+#    #+#             */
/*   Updated: 2023/06/24 17:23:21 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

/*###############################################################
#		* Includes :		    							 	#
###############################################################*/
# include "libft.h"
# include "defines.h"

/*###############################################################
#		* token Types :		    							 	#
###############################################################*/
typedef struct s_token
{
	char	*name;
	int		type;
}	t_token;

/*###############################################################
#		* Functions :		    							 	#
###############################################################*/
// token functions :
t_token		*create_token(char *start, char *end, int type);
t_list		*listadd_token(t_list **list, t_token *new_token);
void		free_token(void *content);

// token getters and setters :
char		*get_token_name(t_list *token);
int			get_token_type(t_list *token);
void		set_token_name(t_list *token, char *new_name);
void		set_token_type(t_list *token, int new_type);

#endif /* TOKEN_H */