/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:45:47 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/27 19:03:13 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//=== is_end_of_command =================================================
int	is_end_of_command(t_list *token)
{
	int	type;

	type = get_token_type(token);
	if (!token || type == CLOSE_PARENTHESIS || type == AND || type == OR)
		return (TRUE);
	if (type == PIPE || type == SEMICOLON || type == OPEN_PARENTHESIS)
		return (TRUE);
	return (FALSE);
}

//=== is_redirection ====================================================
int	is_redirection(t_list *token)
{
	int	type;

	type = get_token_type(token);
	if (type == REDIR_IN || type == HERE_DOC)
		return (TRUE);
	if (type == REDIR_OUT || type == REDIR_APPEND)
		return (TRUE);
	return (FALSE);
}

//=== get_argument ======================================================
char	*join_argument(t_list *tokens)
{
	char	*arg;
	int		index;

	index = 0;
	arg = ft_strdup("");
	if (arg == NULL)
		return (free(arg), NULL);
	while (is_end_of_command(tokens) == FALSE)
	{
		if (is_redirection(tokens) == TRUE)
		{
			if (tokens->next == NULL)
				return (free(arg), NULL);
			tokens = tokens->next->next;
			continue ;
		}
		if (index++)
			arg = ft_vstrjoin(3, arg, S_SPACE, get_token_name(tokens));
		else
			arg = ft_vstrjoin(2, arg, get_token_name(tokens));
		tokens = tokens->next;
	}
	return (arg);
}

//=== extract_files =====================================================
t_list	*extract_files(t_list *tokens)
{
	t_list	*files;
	char	*name;
	int		type;

	files = NULL;
	while (is_end_of_command(tokens) == FALSE)
	{
		if (is_redirection(tokens) == TRUE)
		{
			type = get_token_type(tokens);
			name = get_token_name(tokens->next);
			listadd_file(&files, create_file(name, type));
			if (files == NULL || tokens->next == NULL || (type == HERE_DOC
					&& g_sys.merrno == -1 && run_heredoc(ft_lstlast(files))))
			{
				g_sys.merrno = 9;
				close_iofile_pipe(files, FALSE);
				return (ft_lstclear(&files, clean_file), NULL);
			}
			tokens = tokens->next;
		}
		tokens = tokens->next;
	}
	return (files);
}

//=== clean tree ========================================================
void	clean_tree(t_node *head)
{
	int	node_type;

	if (head != NULL)
	{
		node_type = get_node_type(head);
		if (node_type != COMMAND)
		{
			clean_tree(get_left_node(head));
			clean_tree(get_right_node(head));
			clean_operator((t_operator *)head);
		}
		else if (node_type == COMMAND)
		{
			clean_command((t_command *)head);
		}
	}
}
