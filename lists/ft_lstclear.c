/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:29:24 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/26 12:14:50 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	list = *lst;
	while (list)
	{
		del(list->data);
		tmp = list->next;
		free(list);
		list = tmp;
	}
	*lst = 0;
}
