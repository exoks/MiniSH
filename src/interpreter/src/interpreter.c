//  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣦⣴⣶⣾⣿⣶⣶⣶⣶⣦⣤⣄⠀⠀⠀⠀⠀⠀⠀                                              
//  ⠀⠀⠀⠀⠀⠀⠀⢠⡶⠻⠛⠟⠋⠉⠀⠈⠤⠴⠶⠶⢾⣿⣿⣿⣷⣦⠄⠀⠀⠀           𓐓  interpreter.c 𓐔           
//  ⠀⠀⠀⠀⠀⢀⠔⠋⠀⠀⠤⠒⠒⢲⠀⠀⠀⢀⣠⣤⣤⣬⣽⣿⣿⣿⣷⣄⠀⠀                                              
//  ⠀⠀⠀⣀⣎⢤⣶⣾⠅⠀⠀⢀⡤⠏⠀⠀⠀⠠⣄⣈⡙⠻⢿⣿⣿⣿⣿⣿⣦⠀      Dev: oezzaou <oussama.ezzaou@gmail.com> 
//  ⢀⠔⠉⠀⠊⠿⠿⣿⠂⠠⠢⣤⠤⣤⣼⣿⣶⣶⣤⣝⣻⣷⣦⣍⡻⣿⣿⣿⣿⡀                                              
//  ⢾⣾⣆⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇                                              
//  ⠀⠈⢋⢹⠋⠉⠙⢦⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇       Created: 2025/02/24 11:00:09 by oezzaou
//  ⠀⠀⠀⠑⠀⠀⠀⠈⡇⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇       Updated: 2025/02/24 11:01:34 by oezzaou
//  ⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢀⣾⣿⣿⠿⠟⠛⠋⠛⢿⣿⣿⠻⣿⣿⣿⣿⡿⠀                                              
//  ⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⢠⣿⣟⣭⣤⣶⣦⣄⡀⠀⠀⠈⠻⠀⠘⣿⣿⣿⠇⠀                                              
//  ⠀⠀⠀⠀⠀⠱⠤⠊⠀⢀⣿⡿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠘⣿⠏⠀⠀                             𓆩♕𓆪      
//  ⠀⠀⠀⠀⠀⡄⠀⠀⠀⠘⢧⡀⠀⠀⠸⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠐⠋⠀⠀⠀                     𓄂 oussama ezzaou𓆃  
//  ⠀⠀⠀⠀⠀⠘⠄⣀⡀⠸⠓⠀⠀⠀⠠⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                              

#include "interpreter.h"

//===<[ interpreter: ]>=========================================================
int	interpreter(t_node *root)
{
	g_sys.area = INTERPRETER;
	if (root == NULL || g_sys.merrno != -1)
	{
		if (g_sys.merrno != -1)
			g_sys.exit_status = (g_sys.merrno != -1);
		g_sys.merrno = -1;
		return (0);
	}
	exec_branches(root);
	g_sys.exit_status = extract_exit_status(root, FALSE);
	return (SUCCESS);
}

//===<[ exec_branches: ]>=======================================================
pid_t	exec_branches(t_node *node)
{
	pid_t		pid;

	while (node)
	{
		create_pipe(&g_sys.pipeline, (node->type == PIPE));
		if (node->type == COMMAND)
			pid = exec_cmd(node);
		else if (node->type == SUBSHELL)
			pid = exec_subshell(node);
		else if (get_left_node(node)->type == COMMAND)
			pid = exec_cmd(get_left_node(node));
		else if (get_left_node(node)->type == SUBSHELL)
			pid = exec_subshell(get_left_node(node));
		else
			pid = exec_branches(get_left_node(node));
		if (node->type == AND || node->type == OR)
			node->status = extract_exit_status(get_left_node(node), FALSE);
		if (node->type == COMMAND || (node->status != 0 && node->type == AND)
			|| (node->status == 0 && node->type == OR))
			break ;
		update_pipeline(&g_sys.pipeline);
		node = get_right_node(node);
	}
	return (pid);
}

//===<[ exec_subshell: ]>=======================================================
pid_t	exec_subshell(t_node *node)
{
	node->pid = fork();
	if (node->pid < 0)
		perror("Error creating child process ...\n");
	if (node->pid == 0)
	{
		if (g_sys.pipeline.fd[1] > -1)
			dup2(g_sys.pipeline.fd[1], 1);
		close_pipe(g_sys.pipeline.fd);
		exec_branches(get_left_node(node));
		close(g_sys.pipeline.offset);
		exit(extract_exit_status(get_left_node(node), FALSE));
	}
	return (node->pid);
}

//===<[ exec_builtins: ]>=======================================================
int	exec_builtins(t_node *cmd, int *in_out)
{
	int	index;
	int	status;

	index = -1;
	while (++index < 8)
	{
		if (ft_strcmp(get_cmd_name(cmd), g_sys.builtins.name[index]) == 0)
		{
			g_sys.merrno = -1;
			if (in_out)
			{
				dup2(in_out[0], 0);
				dup2(in_out[1], 1);
			}
			status = g_sys.builtins.func[index](get_cmd_args(cmd));
			if (in_out)
			{
				dup2(g_sys.std_in, 0);
				dup2(g_sys.std_out, 1);
			}
			return (status);
		}
	}
	return (ERROR);
}

//===<[ extract_exit_status: ]>=================================================
pid_t	extract_exit_status(t_node *node, int sig)
{
	t_node	*lnode;

	while (node)
	{
		lnode = get_left_node(node);
		if (node->status == -1
			&& (node->type == COMMAND || node->type == SUBSHELL))
			node->status = waitnode(node, &sig);
		else if (lnode && lnode->status == -1
			&& (lnode->type == COMMAND || lnode->type == SUBSHELL))
			lnode->status = waitnode(lnode, &sig);
		else if (node->type != AND && node->type != OR && lnode->type == PIPE)
			extract_exit_status(lnode, sig);
		if (node->type == COMMAND || node->type == SUBSHELL
			|| (node->status != 0 && node->type == AND)
			|| (node->status == 0 && node->type == OR))
			break ;
		node = get_right_node(node);
	}
	return (node->status * !sig + 130 * sig);
}
