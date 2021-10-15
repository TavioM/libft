/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:37:26 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/15 14:06:21 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL.h"

static t_list	*find_fd(t_list **list, int fd)
{
	t_list	*tmp;

	if (!(*list))
	{
		*list = new_list_fd(fd);
		return (*list);
	}
	tmp = *list;
	while (tmp)
	{
		if (((t_fd *)tmp->data)->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = new_list_fd(fd);
	if (!tmp)
		return (0);
	ft_lstadd_back(list, tmp);
	return (ft_lstlast(*list));
}

static int	read_line(t_list *list)
{
	int		i;
	int		fd;
	int		size;
	t_list	*tmp;
	t_list	*buff;

	size = 0;
	fd = ((t_fd *)list->data)->fd;
	buff = ((t_fd *)list->data)->list;
	while (1)
	{
		i = ((t_buff *)buff->data)->i;
		while (i < ((t_buff *)buff->data)->end)
		{
			if ((((t_buff *)buff->data)->str)[i] == '\n')
				return (size + 1);
			i++;
			size++;
		}
		if (((t_buff *)buff->data)->end < BUFFSIZE)
			return (size + 1);
		tmp = new_buff(fd);
		if (!tmp)
			return (-1);
		ft_lstadd_back(&(((t_fd *)list->data)->list), tmp);
		buff = buff->next;
	}
}

static int	copy_line(int size, t_list *list, char **line)
{
	int		i;
	t_list	*tmp;

	*line = malloc(sizeof(char) * size);
	if (!(*line))
	{
		ft_lstclear(&list, (void (*)(void *)) & free_fd);
		return (-1);
	}
	i = 0;
	while (((t_fd *)list->data)->list && i < size)
	{
		while (((t_fd *)list->data)->list && ((t_buff *)((t_fd *)list->data)->list->data)->i < ((t_buff *)((t_fd *)list->data)->list->data)->end && i < size)
		{
			(*line)[i++] = (((t_buff *)((t_fd *)list->data)->list->data)->str)[(((t_buff *)((t_fd *)list->data)->list->data)->i)++];
		}
		if (((t_buff *)((t_fd *)list->data)->list->data)->i == ((t_buff *)((t_fd *)list->data)->list->data)->end)
		{
			tmp = ((t_fd *)list->data)->list->next;
			ft_lstdelone(((t_fd *)list->data)->list, (void (*)(void *)) & free_buff);
			((t_fd *)list->data)->list = tmp;
		}
	}
	if (!(((t_fd *)list->data)->list))
		ft_lstdelone(list, (void (*)(void *))&free_fd);
	(*line)[i - (i == size)] = 0;
	return (i == size);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*list_fd = 0;
	t_list			*tmp;
	int				size;

	if (fd < 0 || !line || read(fd, 0, 0) == -1)
		return (-1);
	tmp = find_fd(&list_fd, fd);
	if (!tmp)
		return (-1);
	if (!(((t_fd *)tmp->data)->list))
	{
		((t_fd *)tmp->data)->list = new_buff(fd);
		if (!(((t_fd *)tmp->data)->list))
			return (-1);
	}
	size = read_line(tmp);
	ft_printf("size = %2d, ", size);
	if (size < 0)
	{
		ft_lstclear(&list_fd, (void (*)(void *))&free_fd);
		list_fd = 0;
		return (-1);
	}
	return (copy_line(size, tmp, line));
}
