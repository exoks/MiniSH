/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:22:16 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/23 20:40:10 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	minishell_env(char **args)
{
	t_list	*cursor;
	char	*name;
	char	*value;

	(void)args;
	cursor = g_sys.env;
	while (cursor != NULL)
	{
		name = get_var_name(cursor);
		value = get_var_value(cursor);
		if (value != NULL)
			printf("%s=%s\n", name, value);
		cursor = cursor->next;
	}
	return (EXIT_SUCCESS);
}
