/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:05:02 by hael-mou          #+#    #+#             */
/*   Updated: 2025/02/24 11:27:51 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//===<[ minishell_init: ]>======================================================
void	minishell_init(char **env)
{
	g_sys.std_in = dup(STDIN_FILENO);
	g_sys.std_out = dup(STDOUT_FILENO);
	if (g_sys.std_in != ERROR && g_sys.std_out != ERROR)
	{
		minishell_export(env);
		printf(CLEAR);
		printf("%s\n", PROG_INFO);
		printf("%s\n", DEVLOPERS);
		g_sys.pipeline.offset = -1;
		g_sys.pipeline.fd[0] = -1;
		g_sys.pipeline.fd[1] = -1;
		g_sys.merrno = -1;
		builtins_init(&g_sys.builtins);
		return ;
	}
	exit (ERROR);
}

//=== builtins_init ===========================================================
void	builtins_init(t_built *builtins)
{
	builtins->name[0] = "echo";
	builtins->func[0] = minishell_echo;
	builtins->name[1] = "pwd";
	builtins->func[1] = minishell_pwd;
	builtins->name[2] = "env";
	builtins->func[2] = minishell_env;
	builtins->name[3] = "export";
	builtins->func[3] = minishell_export;
	builtins->name[4] = "unset";
	builtins->func[4] = minishell_unset;
	builtins->name[5] = "cd";
	builtins->func[5] = minishell_cd;
	builtins->name[6] = "exit";
	builtins->func[6] = minishell_exit;
	builtins->name[7] = "clear";
	builtins->func[7] = minishell_clear;
}

//=== minishell_ignore ========================================================
void	minishell_ignore(int argc, char **argv)
{
	(void) argc;
	(void) argv;
}

//===<[ minishell_clean: ]>=====================================================
void	minishell_clean(t_minish *minish)
{
	clean_tree(minish->tree);
	free(minish->input);
}
