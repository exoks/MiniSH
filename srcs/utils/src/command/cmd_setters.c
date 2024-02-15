/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 00:05:32 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/28 16:53:01 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

//=== set command pid =========================================================
void	set_cmd_pid(t_node *cmd, pid_t pid)
{
	if (cmd != NULL && cmd->type == COMMAND)
	{
		((t_command *)cmd)->pid = pid;
	}
}

//=== set command name ========================================================
void	set_cmd_name(t_node *cmd, char *name)
{
	if (cmd != NULL && cmd->type == COMMAND)
	{
		((t_command *)cmd)->name = name;
	}
}

//=== set command path ========================================================
void	set_cmd_path(t_node *cmd, char *path)
{
	if (cmd != NULL && cmd->type == COMMAND)
	{
		((t_command *)cmd)->path = path;
	}
}

//=== set command args ========================================================
void	set_cmd_args(t_node *cmd, char **args)
{
	if (cmd != NULL && cmd->type == COMMAND)
	{
		((t_command *)cmd)->args = args;
	}
}

//=== set command iofile ======================================================
void	set_cmd_iofile(t_node *cmd, t_list *iofiles)
{
	if (cmd != NULL && cmd->type == COMMAND)
	{
		((t_command *)cmd)->in_out = iofiles;
	}
}
