/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:35:03 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/14 16:39:10 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"

# define BUFFSIZE 10

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

void	free_buff(t_buff *buff);
void	free_fd(t_fd *fd);
t_list	*new_list_fd(int fd);
t_list	*new_buff(int fd);

#endif
