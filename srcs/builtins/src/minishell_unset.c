/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_unset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:43:16 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/23 18:54:18 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

//=== minishell export =========================================================
int	minishell_unset(char **args)
{
	int	index;
	int	status;

	status = 0;
	index = (args && !ft_strcmp(*args, "unset")) - 1;
	if (args == NULL || args[index + 1] == NULL)
		return (EXIT_FAILURE);
	while (args[++index] != NULL)
	{
		if (invalid_name("unset", args[index]))
			continue ;
		ft_lstrmif(&g_sys.env, args[index], var_cmp, clean_var);
		status += SUCCESS;
	}
	return (!(status == index - !ft_strcmp(*args, "unset")));
}
