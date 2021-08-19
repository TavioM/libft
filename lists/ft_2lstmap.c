/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:29:42 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/19 16:36:40 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_2list	*ft_lstmap(t_2list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_2list	*start;
	t_2list	*list;

	if (!lst || !f)
		return (0);
	start = ft_2lstnew(f(lst->content));
	if (!start)
		return (0);
	lst = lst->next;
	while (lst)
	{
		list = ft_2lstnew(f(lst->content));
		if (!list)
		{
			ft_2lstclear(&start, del);
			return (0);
		}
		ft_2lstadd_back(&start, list);
		lst = lst->next;
	}
	return (start);
}
