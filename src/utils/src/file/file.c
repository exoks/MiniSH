/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:13:38 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/26 15:48:52 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

//=== create_file ==============================================================
t_file	*create_file(char *name, int type)
{
	t_file	*new_file;

	new_file = ft_calloc(1, sizeof(t_file));
	if (new_file == NULL)
		return (NULL);
	new_file->name = ft_strdup(name);
	new_file->type = type;
	new_file->fd = -1;
	if (new_file->name == NULL)
	{
		free(new_file);
		new_file = NULL;
	}
	return (new_file);
}

//=== clean_file ===============================================================
void	clean_file(void *file)
{
	if (file != NULL)
	{
		free(((t_file *)file)->name);
		free(file);
	}
}

//=== listadd_file =============================================================
void	listadd_file(t_list **list, t_file *new_file)
{
	t_list	*new_node;

	if (list == NULL || new_file == NULL)
		return ;
	new_node = ft_lstnew(new_file);
	ft_lstadd_back(list, new_node);
	if (new_node == NULL)
	{
		ft_lstclear(list, clean_file);
	}
}
