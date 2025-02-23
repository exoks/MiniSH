/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:40:15 by oezzaou           #+#    #+#             */
/*   Updated: 2022/10/23 12:18:05 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

//====<[ Function: prototypes ]>================================================
t_buff	*ft_lstcreat(int fd, char *buff, int *size);
char	*get_line_from_rest(char *rest);
char	*get_line_from_lst(t_buff *lst, char *rest, int size);
int		ft_is_nl_exist(char *buff);

//====<[ get_next_line ]>=======================================================
char	*get_next_line(int fd)
{
	static char	rest[OPEN_MAX][BUFFER_SIZE];
	char		*line;
	t_buff		*lst;
	int			size;

	lst = 0;
	size = 0;
	line = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	if (ft_is_nl_exist((char *)rest[fd]))
		return (get_line_from_rest(rest[fd]));
	lst = ft_lstcreat(fd, line, &size);
	if (!lst && !*rest[fd])
		return (0);
	line = get_line_from_lst(lst, rest[fd], ++size);
	ft_lstclear(&lst);
	return (line);
}

//====<[ ft_lstcreate: ]>=======================================================
t_buff	*ft_lstcreat(int fd, char *buff, int *size)
{
	t_buff	*lst;
	int		n_read;

	lst = 0;
	n_read = 1;
	while (n_read && !ft_is_nl_exist(buff))
	{
		buff = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buff)
			return (0);
		n_read = read(fd, buff, BUFFER_SIZE);
		if (n_read == -1 || n_read == 0)
		{
			free(buff);
			if (n_read == -1)
				return (ft_lstclear(&lst));
			return (lst);
		}
		if (lst)
			(ft_lstlast(lst))->next = ft_lstnew(buff);
		else
			lst = ft_lstnew(buff);
		(*size)++;
	}
	return (lst);
}

//====<[ get_line_from_rest: ]>=================================================
char	*get_line_from_rest(char *rest)
{
	char	*line;
	int		l;
	int		i;

	l = -1;
	while (rest[++l] && rest[l] != '\n')
		;
	line = ft_calloc(l + 2, 1);
	if (!line)
		return (0);
	l = -1;
	while (rest[++l] && rest[l] != '\n')
		line[l] = rest[l];
	line[l] = '\n';
	i = 0;
	while (rest[++l])
		rest[i++] = rest[l];
	rest[i] = 0;
	return (line);
}

//====<[ get_line_from_lst: ]>==================================================
char	*get_line_from_lst(t_buff *lst, char *rest, int size)
{
	char	*line;
	int		i;

	line = ft_calloc((size * BUFFER_SIZE) + 1, 1);
	if (!line)
		return (0);
	if (*rest)
		ft_strcat(line, rest);
	*rest = 0;
	while (lst)
	{
		if (lst->buff)
			ft_strcat(line, lst->buff);
		lst = lst->next;
	}
	i = -1;
	while (line[++i] && line[i] != '\n')
		;
	while (line[++i])
	{
		*(rest++) = line[i];
		line[i] = 0;
	}
	*rest = 0;
	return (line);
}

//====<[ is_nl_exist: ]>========================================================
int	ft_is_nl_exist(char *buff)
{
	if (!buff)
		return (0);
	while (*buff && *buff != '\n')
		buff++;
	if (*buff == '\n')
		return (1);
	return (0);
}
