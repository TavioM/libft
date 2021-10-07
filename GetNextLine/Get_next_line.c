/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:37:26 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/07 17:49:09 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*new_list(int fd)
{
	t_list	*new_list;
	t_fd	*new_fd;

	new_fd = malloc(sizeof(t_fd));
	if (!new_fd)
		return (0);
	new_list = ft_lstnew(new_fd);
	if (!new_list)
		free(new_fd);
	((t_fd *)new_list->data)->fd = fd;
	((t_fd *)new_list->data)->buff = 0;
	return (new_list);
}

static t_list	*find_fd(t_list **list, int fd)
{
	t_list	*tmp;

	if (!(*list))
	{
		*list = new_list(fd);
		return (*list);
	}
	tmp = *list;
	while (tmp)
	{
		if (((t_fd *)tmp->data)->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = new_list(fd);
	if (!tmp)
		return (0);
	ft_lstadd_back(list, tmp);
	return (ft_lstlast(*list));
}

void	read_line(t_list *list)
{
	int		fd;
	t_list	*buff;

	fd = ((t_fd *)list->data)->fd;
	buff = ((t_fd *)list->data)->buff;
	while (1)
	{
		if (!(((t_fd *)list->data)->buff))
		{
			((t_fd *)list->data)->buff = malloc(sizeof(char) * BUFFSIZE);
			((t_buff *)(buff->data))->end =
				read(fd, &((t_buff *)(buff->data))->str, 0);
		}
		return ;
	}
}

int	get_next_line(int fd, char **line)
{
	static t_list	*list_fd = 0;
	t_list			*tmp;

	if (fd < 0 || !line || read(fd, 0, 0) == -1)
		return (-1);
	tmp = find_fd(&list_fd, fd);
	if (!tmp)
		return (-1);
	read_line(tmp);
//	ft_printf("fd :%d\n", fd);
	return (0);
}
