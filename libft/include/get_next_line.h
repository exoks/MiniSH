/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:18:56 by oezzaou           #+#    #+#             */
/*   Updated: 2022/10/23 13:29:42 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//====<[ Include guards: ]>=====================================================
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//====<[ Macros: ]>=============================================================
# define BUFFER_SIZE 5

//====<[ Headers: ]>============================================================
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

//====<[ Struct: buff ]>========================================================
typedef struct s_buff
{
	char			*buff;
	struct s_buff	*next;
}t_buff;

//====<[ Function: prototypes ]>================================================
t_buff	*ft_lstnew(char *buff);
t_buff	*ft_lstlast(t_buff *lst);
t_buff	*ft_lstclear(t_buff **head);
char	*ft_strcat(char *dst, char *src);
void	*ft_calloc(size_t count, size_t size);

#endif
//==============================================================================
