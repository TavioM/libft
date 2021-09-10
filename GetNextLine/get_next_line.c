/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:02:53 by ocmarout          #+#    #+#             */
/*   Updated: 2021/09/10 12:41:27 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	*ft_find_fd(t_list_fd **list_fd, int fd)
{
	t_list_fd	*cpy;
	t_list_fd	*tmp;

	tmp = *list_fd;
	cpy = *list_fd;
	if (*list_fd && (*list_fd)->fd == fd)
		return (0);
	while (cpy)
	{
		if (cpy->fd == fd)
		{
			while (tmp->next != cpy)
				tmp = tmp->next;
			tmp->next = cpy->next;
			cpy->next = *list_fd;
			*list_fd = cpy;
			return (0);
		}
		cpy = cpy->next;
	}
	*list_fd = malloc(sizeof(t_list_fd));
	if (!(*list_fd))
		return (0);
	(*list_fd)->next = tmp;
	(*list_fd)->fd = fd;
	(*list_fd)->begin = 0;
	return (0);
}

int	ft_find_line(t_list *list, int fd)
{
	int		i;
	int		size;

	size = 0;
	while (1)
	{
		i = list->start;
		while (i < list->end)
		{
			if ((list->buff)[i] == '\n')
				return (size + 1);
			i++;
			size++;
		}
		if (list->end < BUFFER_SIZE)
			return (size + 1);
		list->next = ft_create_list(fd);
		if (!(list->next))
			return (-1);
		list = list->next;
	}
}

int	ft_cpy_line(int size, t_list_fd **list, char **line)
{
	int		i;
	t_list	*tmp;

	*line = malloc(sizeof(char) * size);
	if (!(*line))
		return (ft_free_list_fd(list, -1));
	i = 0;
	while ((*list)->begin && i < size)
	{
		while ((*list)->begin && (*list)->begin->start < (*list)->begin->end
			&& i < size)
			(*line)[i++] = ((*list)->begin->buff)[((*list)->begin->start)++];
		if ((*list)->begin->start == (*list)->begin->end)
		{
			tmp = (*list)->begin->next;
			free((*list)->begin->buff);
			free((*list)->begin);
			(*list)->begin = tmp;
		}
	}
	if (!((*list)->begin))
		ft_free_link(list);
	(*line)[i - (i == size)] = 0;
	return (i == size);
}

int	get_next_line(int fd, char **line)
{
	int					size;
	static t_list_fd	*list = 0;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (-1);
	ft_find_fd(&list, fd);
	if (!(list->begin))
		list->begin = ft_create_list(fd);
	if (!(list->begin))
		return (-1);
	if (!(list->begin->end))
	{
		ft_free_list(&list);
		*line = malloc(sizeof(char));
		if (!(*line))
			return (-1);
		**line = 0;
		return (0);
	}
	size = ft_find_line(list->begin, fd);
	if (size < 0)
		return (ft_free_list_fd(&list, -1));
	return (ft_cpy_line(size, &list, line));
}
