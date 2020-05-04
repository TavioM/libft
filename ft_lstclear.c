/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:17:34 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/04 11:52:47 by ocmarout         ###   ########.fr       */
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
