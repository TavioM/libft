/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:03:19 by ocmarout          #+#    #+#             */
/*   Updated: 2021/09/10 12:32:31 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_list(t_list_fd **list)
{
	t_list	*tmp;

	while ((*list)->begin)
	{
		free((*list)->begin->buff);
		tmp = (*list)->begin->next;
		free((*list)->begin);
		(*list)->begin = tmp;
	}
}

int	ft_free_list_fd(t_list_fd **list, int ret)
{
	t_list_fd	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		ft_free_list(list);
		*list = tmp;
	}
	return (ret);
}

t_list	*ft_create_list(int fd)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!(list))
		return (0);
	list->buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (!(list->buff))
	{
		free(list);
		return (0);
	}
	list->end = read(fd, list->buff, BUFFER_SIZE);
	if (list->end < 0)
	{
		free(list->buff);
		free(list);
		return (0);
	}
	if (list->end < BUFFER_SIZE)
		(list->buff)[list->end] = 0;
	list->start = 0;
	list->next = 0;
	return (list);
}

void	ft_free_link(t_list_fd **list)
{
	t_list_fd	*tmp;

	tmp = (*list)->next;
	free(*list);
	*list = tmp;
}
