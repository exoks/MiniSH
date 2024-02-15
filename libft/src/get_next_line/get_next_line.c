/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:15:43 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/16 16:48:17 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	backup[BUFFER_SIZE];
	char		*line;
	int			backuplen;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup[0])
	{
		line = gnl_realloc(backup, 0, &backuplen, NO);
		if (!line)
			return (NULL);
		line[backuplen] = 0;
		backup[0] = 0;
	}
	line = readblock(fd, line);
	if (!line)
		return (NULL);
	line = subblock(line, backup);
	return (line);
}

char	*readblock(int fd, char *str)
{
	ssize_t	readed;
	int		oldlen;

	readed = 1;
	while (readed && !isendline(str))
	{
		str = gnl_realloc(str, BUFFER_SIZE, &oldlen, YES);
		if (!str)
			return (NULL);
		readed = read(fd, str + oldlen, BUFFER_SIZE);
		if (readed < 0 || (!readed && !oldlen))
		{
			free(str);
			return (NULL);
		}
		str[readed + oldlen] = 0;
	}
	return (str);
}

char	*subblock(char *str, char *backup)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	while (str[i])
		*backup++ = str[i++];
	*backup = 0;
	free(str);
	return (line);
}
