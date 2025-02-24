//  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣦⣴⣶⣾⣿⣶⣶⣶⣶⣦⣤⣄⠀⠀⠀⠀⠀⠀⠀                                              
//  ⠀⠀⠀⠀⠀⠀⠀⢠⡶⠻⠛⠟⠋⠉⠀⠈⠤⠴⠶⠶⢾⣿⣿⣿⣷⣦⠄⠀⠀⠀            𓐓  parse_tree.c 𓐔           
//  ⠀⠀⠀⠀⠀⢀⠔⠋⠀⠀⠤⠒⠒⢲⠀⠀⠀⢀⣠⣤⣤⣬⣽⣿⣿⣿⣷⣄⠀⠀                                              
//  ⠀⠀⠀⣀⣎⢤⣶⣾⠅⠀⠀⢀⡤⠏⠀⠀⠀⠠⣄⣈⡙⠻⢿⣿⣿⣿⣿⣿⣦⠀      Dev: oezzaou <oussama.ezzaou@gmail.com> 
//  ⢀⠔⠉⠀⠊⠿⠿⣿⠂⠠⠢⣤⠤⣤⣼⣿⣶⣶⣤⣝⣻⣷⣦⣍⡻⣿⣿⣿⣿⡀                                              
//  ⢾⣾⣆⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇                                              
//  ⠀⠈⢋⢹⠋⠉⠙⢦⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇       Created: 2025/02/24 09:47:45 by oezzaou
//  ⠀⠀⠀⠑⠀⠀⠀⠈⡇⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇       Updated: 2025/02/24 09:47:49 by oezzaou
//  ⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢀⣾⣿⣿⠿⠟⠛⠋⠛⢿⣿⣿⠻⣿⣿⣿⣿⡿⠀                                              
//  ⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⢠⣿⣟⣭⣤⣶⣦⣄⡀⠀⠀⠈⠻⠀⠘⣿⣿⣿⠇⠀                                              
//  ⠀⠀⠀⠀⠀⠱⠤⠊⠀⢀⣿⡿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠘⣿⠏⠀⠀                             𓆩♕𓆪      
//  ⠀⠀⠀⠀⠀⡄⠀⠀⠀⠘⢧⡀⠀⠀⠸⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠐⠋⠀⠀⠀                     𓄂 oussama ezzaou𓆃  
//  ⠀⠀⠀⠀⠀⠘⠄⣀⡀⠸⠓⠀⠀⠀⠠⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                              

#include "parser.h"

//===<[ parse_seq: ]>===========================================================
t_node	*parse_seq(t_list **tokens)
{
	t_node	*seq;

	seq = parse_and_or(tokens);
	if (tokens != NULL && *tokens != 0 && get_token_type(*tokens) == SEMICOLON)
	{
		*tokens = (*tokens)->next;
		seq = create_operator_node(seq, parse_seq(tokens), SEMICOLON);
	}
	return (seq);
}

//===<[ parse_and_or: ]>========================================================
t_node	*parse_and_or(t_list **tokens)
{
	t_node	*and_or;
	int		type;

	and_or = parse_pipe(tokens);
	if (tokens != NULL)
		type = get_token_type(*tokens);
	if (tokens != NULL && *tokens != 0 && (type == AND || type == OR))
	{
		*tokens = (*tokens)->next;
		and_or = create_operator_node(and_or, parse_and_or(tokens), type);
	}
	return (and_or);
}

//===<[ parse_pipe: ]>==========================================================
t_node	*parse_pipe(t_list **tokens)
{
	t_node	*pipe;

	if (tokens && *tokens && get_token_type(*tokens) == OPEN_PARENTHESIS)
		pipe = parse_subshell(tokens);
	else
		pipe = parse_command(tokens);
	if (tokens && *tokens != 0 && get_token_type(*tokens) == PIPE)
	{
		*tokens = (*tokens)->next;
		pipe = create_operator_node(pipe, parse_pipe(tokens), PIPE);
	}
	return (pipe);
}

//===<[ parse_command: ]>=======================================================
t_node	*parse_command(t_list **tokens)
{
	t_node	*cmd;

	cmd = create_command_node();
	if (cmd == NULL)
		return (NULL);
	set_cmd_name(cmd, join_argument(*tokens));
	set_cmd_iofile(cmd, extract_files(*tokens));
	while (is_end_of_command(*tokens) == FALSE)
		*tokens = (*tokens)->next;
	return ((t_node *) cmd);
}

//===<[ parse_subshell: ]>======================================================
t_node	*parse_subshell(t_list **tokens)
{
	t_node	*subshell;

	if (tokens && *tokens && get_token_type(*tokens) == OPEN_PARENTHESIS)
		*tokens = (*tokens)->next;
	subshell = create_operator_node(parse_seq(tokens), 0, SUBSHELL);
	if (get_token_type(*tokens) == CLOSE_PARENTHESIS)
		*tokens = (*tokens)->next;
	return (subshell);
}
