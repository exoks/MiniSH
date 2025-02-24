/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:49:20 by hael-mou          #+#    #+#             */
/*   Updated: 2025/02/24 11:28:50 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//=== sigint_hendler ==========================================================
void	sigint_hendler(int signum)
{
	(void) signum;
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 0);
	g_sys.exit_status = 1;
	if (g_sys.area == START)
	{
		rl_on_new_line();
		minishell_prompt();
	}
	if (g_sys.area == START || g_sys.area == LEXER_AREA)
		rl_redisplay();
	if (g_sys.area == PARSER_AREA)
		exit(1);
}

//===	minishell_signal =========================================================
void	minishell_signal(void)
{
	signal(SIGINT, &sigint_hendler);
	signal(SIGQUIT, SIG_IGN);
}

//=== minish_sigign ============================================================
void	minish_sigign(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
