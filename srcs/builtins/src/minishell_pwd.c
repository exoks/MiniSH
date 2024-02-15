/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:42:35 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/23 20:16:42 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	minishell_pwd(char **args)
{
	char	*abs_path;

	(void)args;
	abs_path = getcwd(NULL, 0);
	if (abs_path == NULL)
		return (EXIT_FAILURE);
	ft_putstr_fd(abs_path, 1);
	ft_putchar_fd('\n', 1);
	free(abs_path);
	return (EXIT_SUCCESS);
}
