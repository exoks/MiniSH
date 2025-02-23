/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:02:40 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/28 13:01:07 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

//=== create_operator_node ==============================================
t_node	*create_operator_node(t_node *left, t_node *right, int type)
{
	t_operator	*operator;

	operator = ft_calloc(1, sizeof(t_operator));
	if (operator == NULL)
		return (NULL);
	operator->type = type;
	operator->status = -1;
	operator->left = left;
	operator->right = right;
	return ((t_node *) operator);
}

//=== clean operator ====================================================
void	clean_operator(t_operator *node)
{
	free(node);
}

//=== get_left_node =====================================================
t_node	*get_left_node(t_node *node)
{
	if (node != NULL && node->type != COMMAND)
		return (((t_operator *) node)->left);
	return (NULL);
}

//=== get_right_node ====================================================
t_node	*get_right_node(t_node *node)
{
	if (node != NULL && node->type != COMMAND)
		return (((t_operator *) node)->right);
	return (NULL);
}
