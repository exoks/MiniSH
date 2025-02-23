/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:24:33 by hael-mou          #+#    #+#             */
/*   Updated: 2023/06/25 21:06:59 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

//=== get_token_name ====================================================
char	*get_token_name(t_list *token)
{
	if (token != NULL)
		return (((t_token *)token->content)->name);
	return (NULL);
}

//=== get_token_type ====================================================
int	get_token_type(t_list *token)
{
	if (token != NULL)
		return (((t_token *)token->content)->type);
	return (0);
}

//=== set_token_name ====================================================
void	set_token_name(t_list *token, char *new_name)
{
	if (token != NULL)
		((t_token *)token->content)->name = new_name;
}

//=== set_token_type ====================================================
void	set_token_type(t_list *token, int new_type)
{
	if (token != NULL)
		((t_token *)token->content)->type = new_type;
}
