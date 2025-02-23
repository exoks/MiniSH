/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:59:56 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/28 17:58:29 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

//=== get node type ===========================================================
int	get_node_type(void *node)
{
	t_node	*g_node;

	g_node = node;
	if (g_node != NULL)
		return (g_node->type);
	return (ERROR);
}

//=== waitnode ================================================================
int	waitnode(t_node *node, int *sig)
{
	waitpid(node->pid, &node->status, 0);
	*sig = ((WTERMSIG(node->status) == 2) || (*sig == TRUE));
	return ((((*(int *)&(node->status)) >> 8) & 0x000000ff));
}
