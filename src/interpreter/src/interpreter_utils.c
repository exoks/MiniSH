/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:16:20 by oezzaou           #+#    #+#             */
/*   Updated: 2023/07/27 21:54:09 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

//=== get_env ==================================================================
char	**get_env(t_list *g_env)
{
	char	**env;
	int		index;

	index = 0;
	env = malloc(sizeof(char *) * (ft_lstsize(g_env) + 1));
	if (!env)
		return (NULL);
	while (g_env)
	{
		env[index] = ft_strdup(get_var_name(g_env));
		env[index] = ft_vstrjoin(3, env[index], "=", get_var_value(g_env));
		index++;
		g_env = g_env->next;
	}
	env[index] = NULL;
	return (env);
}

//=== close_iofile_pipes =======================================================
int	close_iofile_pipe(t_list *file, int c_pipe)
{
	while (file)
	{
		close(get_file_fd(file));
		file = file->next;
	}
	if (c_pipe == TRUE)
		close_pipe(g_sys.pipeline.fd);
	close(g_sys.pipeline.offset);
	g_sys.pipeline.offset = -1;
	return (SUCCESS);
}

//=== my_execve ================================================================
int	my_execve(t_node *cmd)
{
	char	**env;

	if (g_sys.merrno <= 2 && exec_builtins(cmd, NULL) == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
	if (g_sys.merrno == -1)
	{
		env = get_env(g_sys.env);
		execve(get_cmd_path(cmd), get_cmd_args(cmd), env);
		ft_free_array(env);
	}
	return (ERROR);
}

//=== get_mode =================================================================
int	get_mode(int type)
{
	int	tmp;

	tmp = O_CREAT | O_WRONLY;
	if (type == REDIR_IN)
		return (O_RDONLY);
	if (type == REDIR_APPEND)
		return (tmp | O_APPEND);
	return (tmp | O_TRUNC);
}

//=== minishell_open ===========================================================
int	minishell_open(t_list *file)
{
	char	**args;
	int		fd;
	int		type;

	type = get_file_type(file);
	args = expand_line(get_file_name(file));
	if (ft_array_size(args) > 1 || *args == NULL)
	{
		g_sys.merrno = 7;
		return (ft_free_array(args), -1);
	}
	free(get_file_name(file));
	set_file_name(file, ft_strdup(*args));
	fd = open(get_file_name(file), get_mode(type), 0644);
	if (fd == ERROR)
	{
		g_sys.merrno += 4 * (access(get_file_name(file), F_OK) == -1);
		if (access(get_file_name(file), R_OK) == -1 && g_sys.merrno == -1)
			g_sys.merrno = 4;
		if ((type == REDIR_OUT || type == REDIR_APPEND) && g_sys.merrno == -1)
			g_sys.merrno = 5;
	}
	return (ft_free_array(args), fd);
}
