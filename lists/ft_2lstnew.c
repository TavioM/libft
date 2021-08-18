/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:11:48 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/18 16:02:20 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_2list	*ft_2lstnew(void *data)
{
	t_2list	*list;

	list = malloc(sizeof(t_2list));
	if (!list)
		return (0);
	list->data = data;
	list->prev = 0;
	list->next = 0;
	return (list);
}
