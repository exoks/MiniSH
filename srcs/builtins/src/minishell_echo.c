/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_echo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:42:13 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/23 18:52:13 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

//=== detect_nflag =============================================================
int	detect_nflag(char **args, int *index)
{
	char	*arg;
	int		nflag;

	nflag = TRUE;
	(*index)--;
	while (args && index && args[++(*index)] && args[*index][0] == '-')
	{
		arg = args[*index] + 1;
		while (*arg != 0)
		{
			if (*arg++ != 'n')
				return (nflag);
		}
		nflag = FALSE;
	}
	return (nflag);
}

//=== minishell_echo ===========================================================
int	minishell_echo(char **args)
{
	int	index;
	int	nflag;

	index = (args && !ft_strcmp(*args, "echo"));
	if (args == NULL)
		return (EXIT_FAILURE);
	nflag = detect_nflag(args, &index);
	while (args[index] != NULL)
	{
		ft_putstr_fd(args[index++], 1);
		if (args[index] != NULL)
			ft_putstr_fd(" ", 1);
	}
	if (nflag == TRUE)
		ft_putstr_fd("\n", 1);
	return (EXIT_SUCCESS);
}
