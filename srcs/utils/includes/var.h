/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:15:26 by hael-mou          #+#    #+#             */
/*   Updated: 2023/06/24 12:56:38 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_H
# define VAR_H

/*###############################################################
#		* Includes :		    							 	#
###############################################################*/
# include "libft.h"
# include "defines.h"

/*###############################################################
#		* Define :		    								 	#
###############################################################*/
# define INVALID_ID	"not a valid identifier\n"

/*###############################################################
#		* Var Types :		    							 	#
###############################################################*/
typedef struct s_var
{
	char	*name;
	char	*value;
}	t_var;

/*###############################################################
#		* Functions :		    							 	#
###############################################################*/
// variable function :
int		set_variable(t_list **vars, char *var);
char	*get_var_name(t_list *var);
char	*get_var_value(t_list *var);
char	*search_var(t_list *vars, char *var_name);

// variable utils:
t_list	*create_variable(char *variable);
int		invalid_name(char *str, char *var_name);
int		var_cmp(void *value1, void *value2);
void	clean_var(void *content);

#endif /* VAR_H */