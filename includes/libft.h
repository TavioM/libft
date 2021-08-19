/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:10:47 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/19 17:39:59 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "ft_printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_2list
{
	void			*data;
	struct s_2list	*prev;
	struct s_2list	*next;
}				t_2list;

size_t			ft_strlen(char const *s);
size_t			ft_strlcpy(char *dest, char const *src, size_t size);
size_t			ft_strlcat(char *dest, char const *src, size_t size);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_check_base(char const *base);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
int				ft_atoi(char const *str);
int				ft_memcmp(void const *s1, void const *s2, size_t n);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			trim_spaces(char *s);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, void const *src, size_t n);
void			*ft_memccpy(void *dst, void const *src, int c, size_t n);
void			*ft_memmove(void *dst, void const *src, size_t len);
void			*ft_memchr(void const *s, int c, size_t n);
char			*ft_strcpy(char *str, char const *src);
char			*ft_strchr(char const *s, int c);
char			*ft_strrchr(char const *s, int c);
char			*ft_strnstr(char const *h, char const *n, size_t l);
char			*ft_strdup(char const *src);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, char const *base);
char			*ft_utoa(unsigned int n);
char			*ft_utoa_base(unsigned int n, char const *base);
char			*bin64_to_hex(uint64_t nb);
char			*ft_substr(char const *s, unsigned int start, size_t l);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *));
t_2list			*ft_2lstnew(void *content);
void			ft_2lstadd_front(t_2list **alst, t_2list *new);
int				ft_2lstsize(t_2list *lst);
t_2list			*ft_2lstlast(t_2list *lst);
void			ft_2lstadd_back(t_2list **alst, t_2list *new);
void			ft_2lstdelone(t_2list *lst);
void			ft_2lstclear(t_2list **lst, void (*del)(void*));
void			ft_2lstiter(t_2list *lst, void (*f)(void *));
t_2list			*ft_2lstmap(t_2list *l, void *(*f)(void *), void (*d)(void *));

#endif
