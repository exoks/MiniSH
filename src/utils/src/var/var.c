/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:29:58 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/23 19:17:21 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "var.h"

//=== set variable ============================================================
int	set_variable(t_list **vars, char *var)
{
	t_list	*new_var;
	t_list	*select;

	new_var = create_variable(var);
	if (new_var == NULL || invalid_name("export", get_var_name(new_var)))
	{
		ft_lstdelone(new_var, clean_var);
		return (FAILURE);
	}
	select = ft_lstsearch(*vars, var_cmp, get_var_name(new_var));
	if (*vars == NULL)
		*vars = new_var;
	else if (select != NULL)
	{
		if (get_var_value(new_var) == NULL)
			return (ft_lstdelone(new_var, clean_var), FAILURE);
		clean_var(select->content);
		select->content = new_var->content;
		free(new_var);
	}
	else
		ft_lstlast(*vars)->next = new_var;
	return (SUCCESS);
}

//=== get variable name =======================================================
char	*get_var_name(t_list *var)
{
	if (var != NULL)
		return (((t_var *)var->content)->name);
	return (NULL);
}

//=== get variable value ======================================================
char	*get_var_value(t_list *var)
{
	if (var != NULL)
		return (((t_var *)var->content)->value);
	return (NULL);
}

//=== search var ==============================================================
char	*search_var(t_list *vars, char *var_name)
{
	t_list	*select;

	select = ft_lstsearch(vars, var_cmp, var_name);
	if (select != NULL)
		return (((t_var *)select->content)->value);
	return (NULL);
}
