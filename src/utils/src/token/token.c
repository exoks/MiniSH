/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:44:32 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/26 16:55:55 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

//=== create_token ======================================================
t_token	*create_token(char *start, char *end, int type)
{
	t_token	*new_token;

	new_token = ft_calloc(1, sizeof(t_token));
	if (new_token == NULL)
		return (NULL);
	new_token->type = type;
	new_token->name = ft_substr(start, 0, (end - start));
	if (new_token->name == NULL)
	{
		free(new_token);
		new_token = NULL;
	}
	return (new_token);
}

//=== listadd_token =====================================================
t_list	*listadd_token(t_list **list, t_token *new_token)
{
	t_list	*new_node;

	new_node = ft_lstnew(new_token);
	if (new_token == NULL || new_node == NULL)
	{
		ft_lstclear(list, free_token);
		return (NULL);
	}
	ft_lstadd_back(list, new_node);
	return (*list);
}

//=== free_token =====================================================
void	free_token(void *content)
{
	t_token	*token;

	token = content;
	if (token != NULL)
		free(token->name);
	free(token);
}
