/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:29:24 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/19 16:35:22 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2lstclear(t_2list **lst, void (*del)(void*))
{
	t_2list	*list;
	t_2list	*tmp;

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
