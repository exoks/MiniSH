/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:42:24 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/28 20:37:27 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

//=== set_new_value ===========================================================
void	set_new_value(char *name, char *value)
{
	char	*var;

	var = ft_vstrjoin(4, NULL, name, "=", value);
	set_variable(&g_sys.env, var);
	free(value);
	free(var);
}

//=== get path ================================================================
char	*get_path(char **args)
{
	char	*path;

	args += (args && !ft_strcmp(*args, "cd"));
	if (args == NULL || *args == NULL)
	{
		path = search_var(g_sys.env, "HOME");
		if (path == NULL)
			return ("/");
		return (path);
	}
	if (ft_strcmp(*args, "-") == 0)
	{
		path = search_var(g_sys.env, "OLDPWD");
		if (path != NULL)
			ft_putendl_fd(path, 2);
		return (path);
	}
	return (*args);
}

//=== minishell cd ===========================================================
int	minishell_cd(char **args)
{
	char	*path;
	char	*opwd;

	path = get_path(args);
	opwd = getcwd(NULL, 0);
	if (path == NULL || chdir(path) == ERROR)
	{
		free(opwd);
		ft_putstr_fd("minishell: cd: ", 2);
		if (path == NULL)
		{
			ft_print_error(OLDPWD_ER);
			return (EXIT_FAILURE);
		}
		perror(path);
		return (EXIT_FAILURE);
	}
	set_new_value("OLDPWD", opwd);
	set_new_value("PWD", getcwd(NULL, 0));
	return (EXIT_SUCCESS);
}
