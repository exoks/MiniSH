/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:12:53 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 22:42:57 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*###############################################################
#  	   * Includes :		    								 	#
###############################################################*/
# include <stdlib.h>
# include <unistd.h>

/*###############################################################
#  	   * Macro definition :										#
###############################################################*/
# define YES 1
# define NO 0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 126 
# endif

/*###############################################################
#  	   * Functions :											#
###############################################################*/
//principal function :
char	*get_next_line(int fd);
char	*readblock(int fd, char *str);
char	*subblock(char *str, char *backup);

//utils function :
int		isendline(char *str);
char	*gnl_realloc(char *str, size_t size, int *oldlen, char free_str);

#endif
