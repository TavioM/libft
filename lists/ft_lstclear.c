/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:17:34 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/19 17:38:22 by ocmarout         ###   ########.fr       */
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
		del(list->content);
		tmp = list->next;
		free(list);
		list = tmp;
	}
	*lst = 0;
}
