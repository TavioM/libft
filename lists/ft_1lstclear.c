/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:17:34 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/26 11:53:19 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_1lstclear(t_1list **lst, void (*del)(void*))
{
	t_1list	*list;
	t_1list	*tmp;

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
