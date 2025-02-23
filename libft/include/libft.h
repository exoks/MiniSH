/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:28:02 by oezzaou           #+#    #+#             */
/*   Updated: 2025/02/23 10:52:12 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//====<[ include guards: ]>=====================================================
#ifndef LIBFT_H
# define LIBFT_H

//====<[ headers: ]>============================================================
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//====<[ macros: ]>=============================================================
# define FALSE	0
# define TRUE	1

//====<[ struct: list ]>========================================================
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//====<[ prototypes: ]>=========================================================
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_vstrjoin(int nstr, char *dst, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void	*content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstrmif(t_list **list, void *ref, int (*cmp)(), void (*del)(void *));
void	ft_strreplace(char *str, char *c1, char c2);
char	*ft_strnjoin(char *string1, char const *string2, size_t n);
void	ft_free_array(char **node);
int		ft_array_size(char **array);
size_t	ft_toklen(const char *string, const char delim);
char	*ft_strtok(char const *string, char delim);
t_list	*ft_lstsearch(t_list *lst, int (*search)(void *, void *), void *value);

char	*get_next_line(int fd);
void	ft_print_error(const char *format, ...);
#endif
//==============================================================================
