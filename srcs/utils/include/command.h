/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:46:06 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/28 16:57:10 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

/*###############################################################
#		* Includes :		    							 	#
###############################################################*/
# include "libft.h"
# include "types.h"
# include "file.h"
# include "defines.h"

/*###############################################################
#		* operator Types :		    						 	#
###############################################################*/
typedef struct s_command
{
	int			type;
	pid_t		pid;
	int			status;
	char		*name;
	char		*path;
	char		**args;
	t_list		*in_out;
}				t_command;

/*###############################################################
#		* Functions :		    							 	#
###############################################################*/
// command function :
t_node	*create_command_node(void);
void	clean_command(t_command *cmd);

// command setters :
void	set_cmd_pid(t_node *cmd, pid_t pid);
void	set_cmd_name(t_node *cmd, char *name);
void	set_cmd_path(t_node *cmd, char *path);
void	set_cmd_args(t_node *cmd, char **args);
void	set_cmd_iofile(t_node *cmd, t_list *iofiles);

// command getters :
pid_t	get_cmd_pid(t_node *cmd);
char	*get_cmd_name(t_node *cmd);
char	*get_cmd_path(t_node *cmd);
char	**get_cmd_args(t_node *cmd);
t_list	*get_cmd_iofile(t_node *cmd);

#endif /* COMMAND_H */
