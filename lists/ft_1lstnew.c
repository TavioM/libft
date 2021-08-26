/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:57:52 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/26 11:54:43 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_1list	*ft_lstnew(void *content)
{
	t_1list	*list;

	list = malloc(sizeof(t_1list));
	if (!list)
		return (0);
	list->content = content;
	list->next = 0;
	return (list);
}
