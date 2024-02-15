/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:26:25 by oezzaou           #+#    #+#             */
/*   Updated: 2023/07/27 18:21:03 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//=== minishell main ===========================================================
int	main(int argc, char **argv, char **env)
{
	t_minish	minish;

	minishell_init(env);
	minishell_ignore(argc, argv);
	minishell_signal();
	while (TRUE)
	{
		g_sys.area = START;
		minish.input = readline(minishell_prompt());
		if (minish.input == NULL)
			return (g_sys.exit_status);
		minish.tokens = lexer(minish.input);
		minish.tree = parser(minish.tokens);
		interpreter(minish.tree);
		add_history(minish.input);
		minishell_clean(&minish);
	}
	return (0);
}
