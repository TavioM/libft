/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:35:03 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/18 18:34:36 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"

# ifndef BUFFSIZE
#  define BUFFSIZE 12
# endif

typedef struct s_fd
{
	int				fd;
	struct s_list	*list;
}					t_fd;

typedef struct s_buff
{
	int				i;
	int				end;
	char			*str;
}					t_buff;

int		get_next_line(int fd, char **line);
void	free_buff(t_buff *buff);
void	free_fd(t_fd *fd);
t_list	*new_list_fd(int fd);
t_list	*new_buff(int fd);

#endif
