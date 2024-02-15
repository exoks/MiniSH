/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:07:00 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/28 20:27:55 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

//=== create_command_node ======================================================
t_node	*create_command_node(void)
{
	t_command	*cmd;

	cmd = ft_calloc(1, sizeof(t_command));
	if (cmd == NULL)
		return (NULL);
	cmd->type = COMMAND;
	cmd->status = -1;
	return ((t_node *)cmd);
}

//=== create_command_node ======================================================
void	clean_command(t_command *cmd)
{
	int	index;

	index = 0;
	if (cmd == NULL)
		return ;
	free(cmd->name);
	free(cmd->path);
	while (cmd->args != NULL && cmd->args[index] != NULL)
		free(cmd->args[index++]);
	free(cmd->args);
	ft_lstclear(&cmd->in_out, clean_file);
	free(cmd);
}
