/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_getters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 00:05:32 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/22 22:38:06 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

//=== get command pid ==========================================================
pid_t	get_cmd_pid(t_node *cmd)
{
	if (cmd != NULL)
		return (((t_command *)cmd)->pid);
	return (ERROR);
}

//=== get command name =========================================================
char	*get_cmd_name(t_node *cmd)
{
	if (cmd != NULL)
		return (((t_command *)cmd)->name);
	return (NULL);
}

//=== get command path =========================================================
char	*get_cmd_path(t_node *cmd)
{
	if (cmd != NULL)
		return (((t_command *)cmd)->path);
	return (NULL);
}

//=== get command args =========================================================
char	**get_cmd_args(t_node *cmd)
{
	if (cmd != NULL)
		return (((t_command *)cmd)->args);
	return (NULL);
}

//=== get command iofile =======================================================
t_list	*get_cmd_iofile(t_node *cmd)
{
	if (cmd != NULL)
		return (((t_command *)cmd)->in_out);
	return (NULL);
}
