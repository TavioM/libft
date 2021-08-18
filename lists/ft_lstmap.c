/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:20:04 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/18 15:22:59 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*list;

	if (!lst || !f)
		return (0);
	start = ft_lstnew(f(lst->content));
	if (!start)
		return (0);
	lst = lst->next;
	while (lst)
	{
		list = ft_lstnew(f(lst->content));
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
