/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:29:42 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/26 12:15:56 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*list;

	if (!lst || !f)
		return (0);
	start = ft_lstnew(f(lst->data));
	if (!start)
		return (0);
	lst = lst->next;
	while (lst)
	{
		list = ft_lstnew(f(lst->data));
		if (!list)
		{
			ft_lstclear(&start, del);
			return (0);
		}
		ft_lstadd_back(&start, list);
		lst = lst->next;
	}
	return (start);
}
