/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:25:28 by hael-mou          #+#    #+#             */
/*   Updated: 2023/07/27 18:57:19 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*###############################################################
#  	   * Includes :		    								 	#
###############################################################*/
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include "list.h"

/*###############################################################
#  	   * Defines :												#
###############################################################*/
# define FALSE	0
# define TRUE	1

/*###############################################################
#  	   * Functions :											#
###############################################################*/
// Checks Functions: 
int		ft_isalpha(int character);
int		ft_isupper(int character);
int		ft_islower(int character);
int		ft_isdigit(int character);
int		ft_isalnum(int character);
int		ft_isascii(int character);
int		ft_isprint(int character);
int		ft_isspace(int character);
int		ft_isxdigit(int character);

// Convert Functions:
int		ft_atoi(const char *string);
char	*ft_itoa(int number);
int		ft_tolower(int character);
int		ft_toupper(int character);

// Print Functions:
void	ft_putchar_fd(char character, int fd);
void	ft_putstr_fd(char *string, int fd);
void	ft_putendl_fd(char *string, int fd);
void	ft_putnbr_fd(int number, int fd);
void	ft_print_error(const char *format, ...);

// Memory Function:
void	*ft_memset(void *memory, int constant, size_t len);
void	ft_bzero(void *memory, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_memchr(const void *memory, int c, size_t len);
int		ft_memcmp(const void *mem1, const void *mem2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);

// String Function:
char	**ft_split(char const *string, char delim);
int		ft_strcout(char const *string, char delim);
size_t	ft_strlen(const char *string);
char	*ft_strdup(const char *string);
char	*ft_strchr(const char *string, int character);
void	ft_striteri(char *string, void (*fun)(unsigned int, char *));
void	ft_strreplace(char *str, char *c1, char c2);
char	*ft_strmapi(char const *string, char (*fun)(unsigned int, char));
char	*ft_strjoin(char *string1, char const *string2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *string1, const char *string2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *string, int character);
char	*ft_strtok(char const *string, char delim);
size_t	ft_toklen(const char *string, const char delim);
char	*ft_strtrim(char const *string, char const *set);
char	*ft_substr(char const *string, unsigned int start, size_t len);
char	*ft_strnjoin(char *string1, char const *string2, size_t n);
char	*ft_vstrjoin(int nstr, char *dst, ...);
void	ft_free_array(char **node);
int		ft_array_size(char **array);

// number:
int		ft_nbrlen(int number);
int		ft_nbrnchr(int *array, int number, int len);

// List :
t_list	*ft_lstnew(void	*content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstsearch(t_list *lst, int (*search)(void *, void *), void *value);
void	ft_lstrmif(t_list **list, void *ref, int (*cmp)(), void (*del)(void *));

#endif
