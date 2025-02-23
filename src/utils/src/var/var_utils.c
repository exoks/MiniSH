/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:05:49 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/23 19:15:01 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "var.h"

//=== create variable  ========================================================
t_list	*create_variable(char *variable)
{
	t_list	*node;
	t_var	*new_var;

	node = ft_lstnew(NULL);
	new_var = ft_calloc(1, sizeof(t_var));
	if (variable == NULL || node == NULL || new_var == NULL)
	{
		return (free(node), free(new_var), NULL);
	}
	new_var->name = ft_strtok(variable, '=');
	if (new_var->name == NULL)
	{
		return (free(node), free(new_var), NULL);
	}
	variable += ft_toklen(variable, '=');
	if (*variable == 0)
		new_var->value = NULL;
	else
		new_var->value = ft_strdup(++variable);
	node->content = new_var;
	return (node);
}

//=== is invalide name ========================================================
int	invalid_name(char *str, char *name)
{
	int		status;
	char	*cursor;

	status = FALSE;
	cursor = name;
	if (!ft_isalpha(*cursor) && *cursor != '_')
		status = TRUE;
	while (!status && *(++cursor) != '\0')
	{
		if (!ft_isalnum(*cursor) && *cursor != '_')
			status = TRUE;
	}
	if (status == TRUE)
		ft_print_error("minishell: %: `%': "INVALID_ID, str, name);
	return (status);
}

//=== cmp value of 2 var ======================================================
int	var_cmp(void *value1, void *value2)
{
	if (ft_strcmp(((t_var *)value1)->name, value2) == 0)
	{
		return (TRUE);
	}
	return (FALSE);
}

//=== set variable ============================================================
void	clean_var(void *content)
{
	t_var	*var_node;

	var_node = content;
	free(var_node->name);
	free(var_node->value);
	free(var_node);
}
