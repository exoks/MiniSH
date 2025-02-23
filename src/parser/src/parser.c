/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:23:32 by oezzaou           #+#    #+#             */
/*   Updated: 2023/07/27 18:11:36 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//=== parse_seq =========================================================
t_node	*parser(t_list *tokens)
{
	t_node	*tree;
	void	*copy;

	copy = tokens;
	g_sys.area = PARSER_AREA;
	minish_sigign();
	if (tokens == NULL)
		return (NULL);
	tree = parse_seq(&tokens);
	minishell_signal();
	clean_tokenizer(copy);
	return (tree);
}
