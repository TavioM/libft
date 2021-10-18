/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:20:21 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/18 18:11:27 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL.h"

void	free_buff(t_buff *buff)
{
	free(buff->str);
	free(buff);
}

void	free_fd(t_fd *fd)
{
	ft_lstclear(&(fd->list), (void (*)(void *)) & free_buff);
	free(fd);
}

t_list	*new_list_fd(int fd)
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

t_list	*new_buff(int fd)
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
