/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:37:26 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/08 19:28:00 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*new_list_fd(int fd)
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
	((t_fd *)new_list->data)->list = 0;
	return (new_list);
}

static t_list	*new_buff(int fd)
{
	t_list	*new_list;
	t_fd	*new_buff;

	new_buff = malloc(sizeof(t_buff));
	if (!new_buff)
		return (0);
	new_list = ft_lstnew(new_buff);
	if (!new_list)
		free(new_buff);
	((t_buff *)new_list->data)->i = 0;
	((t_buff *)new_list->data)->end = 0;
	((t_buff *)new_list->data)->str = malloc(sizeof(char) * BUFFSIZE);
	if (!(((t_buff *)new_list->data)->str))
	{
		free(new_list);
		free(new_buff);
		return (0);
	}
	((t_buff *)new_list->data)->end
		= read(fd, ((t_buff *)new_list->data)->str, BUFFSIZE);
	return (new_list);
}

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
	t_list	**buff;

	size = 0;
	fd = ((t_fd *)list->data)->fd;
	buff = &(((t_fd *)list->data)->list);
	if (!(*buff))
	{
		*buff = new_buff(fd);
		if (!(buff))
			return (-1);
	}
	while (1)
	{
		i = ((t_buff *)(*buff)->data)->i;
		while (i < ((t_buff *)(*buff)->data)->end)
		{
			if ((((t_buff *)(*buff)->data)->str)[i] == '\n')
				return (size + 1);
			i++;
			size++;
		}
		if (((t_buff *)(*buff)->data)->end < BUFFSIZE)
			return (size + 1);
		(*buff)->next = new_buff(fd);
		if (!(*buff)->next)
			return (-1);
		*buff = (*buff)->next;
	}
}

/*	((t_buff)((t_fd)list->data)->list->data)->str;	*/

int	get_next_line(int fd, char **line)
{
	static t_list	*list_fd = 0;
	t_list			*tmp;

	if (fd < 0 || !line || read(fd, 0, 0) == -1)
		return (-1);
	tmp = find_fd(&list_fd, fd);
	ft_printf("still here\n");
	if (!tmp)
		return (-1);
	read_line(tmp);
	return (0);
}
