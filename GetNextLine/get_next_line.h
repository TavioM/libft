/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:03:26 by ocmarout          #+#    #+#             */
/*   Updated: 2021/09/10 12:30:34 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list_fd
{
	int					fd;
	struct s_list		*begin;
	struct s_list_fd	*next;
}				t_list_fd;

typedef struct s_list
{
	char			*buff;
	int				start;
	int				end;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
int				*ft_find_fd(t_list_fd **list_fd, int fd);
int				ft_find_line(t_list *list, int fd);
int				ft_cpy_line(int size, t_list_fd **list, char **line);
t_list			*ft_create_list(int fd);
void			ft_free_list(t_list_fd **list);
int				ft_free_list_fd(t_list_fd **list, int ret);
void			ft_free_link(t_list_fd **list);

#endif
