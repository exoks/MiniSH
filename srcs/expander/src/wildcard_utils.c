/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:52:16 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/26 23:16:21 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

//=== home_path : =============================================================
char	*home_path(char *eline, char **line)
{
	char	*value;

	*line += 1;
	if (*(*line + 1) != '/' && *(*line + 1) != 0 && *(*line + 1) != C_SPACE)
		value = ft_strdup("~");
	else
	{
		value = ft_strdup(search_var(g_sys.env, "HOME"));
		if (value == NULL)
			value = ft_strdup("/");
	}
	eline = ft_vstrjoin(3, eline, S_SPACE, value);
	return (free(value), eline);
}

//=======
t_pattern	get_pattern(char *line)
{
	t_pattern	pattern;
	char		*tmp;
	char		*save;

	save = line;
	ft_memset(&pattern, 0, sizeof(t_pattern));
	pattern.first = ft_strtok(line, C_STAR);
	line += ft_strlen(pattern.first);
	tmp = ft_strrchr(line, C_STAR);
	if (*tmp != 0)
		pattern.last = ft_strdup(tmp + 1);
	*tmp = 0;
	pattern.middle = ft_split(line, C_STAR);
	free(save);
	return (pattern);
}

//=======
int	is_match(char *str, t_pattern *ptn)
{
	char	**middle;
	int		len;

	len = ft_strlen(ptn->first);
	if (ptn->first != NULL && *(ptn->first) != 0)
	{
		if (ft_strncmp(str, ptn->first, len) != 0)
			return (FALSE);
		str += len;
	}
	middle = ptn->middle;
	while (middle && *middle)
	{
		str = ft_strnstr(str, *middle, ft_strlen(str));
		if (str == NULL)
			return (FALSE);
		str += ft_strlen(*middle++);
	}
	len = ft_strlen(str) - ft_strlen(ptn->last);
	if (ptn->last != NULL && *(ptn->last) != 0 && (len < 0
			|| ft_strncmp(str + len, ptn->last, ft_strlen(ptn->last)) != 0))
		return (FALSE);
	return (SUCCESS);
}

//========
char	*extract_star(char *line)
{
	t_pattern	pattern;
	t_dir		dir;
	char		*exp_line;

	pattern = get_pattern(ft_strdup(line));
	dir.stream = opendir(".");
	exp_line = ft_strdup("");
	if (dir.stream == NULL)
		return (clear_pattern(&pattern), NULL);
	dir.info = readdir(dir.stream);
	while (dir.info)
	{
		if (is_match(dir.info->d_name, &pattern))
			exp_line = ft_vstrjoin(3, exp_line, dir.info->d_name, S_SPACE);
		dir.info = readdir(dir.stream);
	}
	if (*exp_line == 0)
	{
		ft_strreplace(line, S_STAR, '*');
		exp_line = ft_vstrjoin(3, exp_line, line, S_SPACE);
	}
	clear_pattern(&pattern);
	return (exp_line);
}

//=========
void	clear_pattern(t_pattern *pattern)
{
	free(pattern->first);
	free(pattern->last);
	ft_free_array(pattern->middle);
}
