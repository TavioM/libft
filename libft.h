/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:10:47 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/07 15:36:57 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

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
int				ft_strncmp(char const *s1, char const *s2, size_t n);
int				ft_atoi(char const *str);
int				ft_memcmp(void const *s1, void const *s2, size_t n);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
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

#endif
