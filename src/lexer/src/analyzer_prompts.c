//  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣦⣴⣶⣾⣿⣶⣶⣶⣶⣦⣤⣄⠀⠀⠀⠀⠀⠀⠀                                              
//  ⠀⠀⠀⠀⠀⠀⠀⢠⡶⠻⠛⠟⠋⠉⠀⠈⠤⠴⠶⠶⢾⣿⣿⣿⣷⣦⠄⠀⠀⠀      𓐓  analyzer_prompts.c 𓐔           
//  ⠀⠀⠀⠀⠀⢀⠔⠋⠀⠀⠤⠒⠒⢲⠀⠀⠀⢀⣠⣤⣤⣬⣽⣿⣿⣿⣷⣄⠀⠀                                              
//  ⠀⠀⠀⣀⣎⢤⣶⣾⠅⠀⠀⢀⡤⠏⠀⠀⠀⠠⣄⣈⡙⠻⢿⣿⣿⣿⣿⣿⣦⠀      Dev: oezzaou <oussama.ezzaou@gmail.com> 
//  ⢀⠔⠉⠀⠊⠿⠿⣿⠂⠠⠢⣤⠤⣤⣼⣿⣶⣶⣤⣝⣻⣷⣦⣍⡻⣿⣿⣿⣿⡀                                              
//  ⢾⣾⣆⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇                                              
//  ⠀⠈⢋⢹⠋⠉⠙⢦⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇       Created: 2025/02/24 10:16:13 by oezzaou
//  ⠀⠀⠀⠑⠀⠀⠀⠈⡇⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇       Updated: 2025/02/24 10:17:32 by oezzaou
//  ⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢀⣾⣿⣿⠿⠟⠛⠋⠛⢿⣿⣿⠻⣿⣿⣿⣿⡿⠀                                              
//  ⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⢠⣿⣟⣭⣤⣶⣦⣄⡀⠀⠀⠈⠻⠀⠘⣿⣿⣿⠇⠀                                              
//  ⠀⠀⠀⠀⠀⠱⠤⠊⠀⢀⣿⡿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠘⣿⠏⠀⠀                             𓆩♕𓆪      
//  ⠀⠀⠀⠀⠀⡄⠀⠀⠀⠘⢧⡀⠀⠀⠸⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠐⠋⠀⠀⠀                     𓄂 oussama ezzaou𓆃  
//  ⠀⠀⠀⠀⠀⠘⠄⣀⡀⠸⠓⠀⠀⠀⠠⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                              

#include "analyzer.h"

//===<[ operator_prompt: ]>=====================================================
t_list	*operator_prompt(t_list *token)
{
	char	*prompt;
	char	*line;
	t_list	*ntokens;

	ntokens = NULL;
	prompt = get_prompt(get_token_type(token));
	while (!ntokens)
	{
		line = readline(prompt);
		if (!line)
			return (set_token_type(token, END), clean_tokenizer(ntokens), NULL);
		ntokens = tokenizer(line);
		free(line);
	}
	return (ntokens);
}

//===<[ subsh_prompt: ]>========================================================
t_list	*subsh_prompt(t_list *token, int eq_point)
{
	t_list	*ntokens;
	int		subshs;
	char	*line;

	ntokens = NULL;
	while (!ntokens)
	{
		subshs = eq_point;
		while (--subshs > 0)
			printf("%-6.5s", SUBSH_PROMPT);
		line = readline(SUBSH_PROMPT);
		if (!line)
			return (set_token_type(token, END), clean_tokenizer(ntokens), NULL);
		ntokens = tokenizer(line);
		free(line);
	}
	return (ntokens);
}

//===<[ quote_prompt: ]>========================================================
t_list	*quote_prompt(t_list *token)
{
	char	*line;
	int		*data;
	void	*tmp;
	t_list	*ntokens;

	line = ft_strdup(get_token_name(token));
	data = (int [3]){get_token_type(token), 0, 0};
	update_quotes_data(line, data);
	while (data[SQUOTES] % 2 || data[DQUOTES] % 2)
	{
		tmp = readline(get_prompt(data[TYPE]));
		if (!tmp)
			return (set_token_type(token, END), free(line), NULL);
		update_quotes_data((char *) tmp, data);
		line = ft_strjoin(line, (char *) tmp);
	}
	tmp = tokenizer(line);
	ntokens = ((t_list *)tmp)->next;
	free(get_token_name(token));
	set_token_name(token, ft_strdup(get_token_name(tmp)));
	set_token_type(token, STRING);
	ft_lstdelone(tmp, free_token);
	return (free(line), ntokens);
}

//===<[ get_prompt: ]>==========================================================
char	*get_prompt(int type)
{
	if (type == PIPE)
		return (PIPE_PROMPT);
	if (type == AND)
		return (AND_PROMPT);
	if (type == OR)
		return (OR_PROMPT);
	if (type == SINGLE_QUOTES)
		return (QUOTE_PROMPT);
	if (type == DOUBLE_QUOTES)
		return (DQUOTE_PROMPT);
	return (NULL);
}
