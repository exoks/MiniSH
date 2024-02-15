/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:43:38 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/26 23:10:05 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	is_not_num(char *str)
{
	char	*cursor;

	cursor = str + (*str == '-');
	while (*cursor != 0)
	{
		if (ft_isdigit(*cursor++) == FALSE)
		{
			ft_print_error("minishell: exit: %: "NONUM_ARG, str);
			g_sys.exit_status = 255;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	many_args(char **args)
{
	if (args[1] == NULL)
		return (FAILURE);
	ft_print_error("minishell: exit: "MUTY_ARG);
	return (TRUE);
}

int	minishell_exit(char **args)
{
	int	index;

	index = (args && !ft_strcmp(*args, "exit"));
	ft_putstr_fd("exit\n", 1);
	if (args == NULL || args[index] == NULL || is_not_num(args[index]))
		exit(g_sys.exit_status);
	if (many_args(&args[index]) == TRUE)
		return (EXIT_FAILURE);
	exit(ft_atoi(args[index]));
}
