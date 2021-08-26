/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1lstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:20:04 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/26 11:54:27 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_1list	*ft_1lstmap(t_1list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_1list	*start;
	t_1list	*list;

	if (!lst || !f)
		return (0);
	start = ft_1lstnew(f(lst->content));
	if (!start)
		return (0);
	lst = lst->next;
	while (lst)
	{
		list = ft_1lstnew(f(lst->content));
		if (!list)
		{
			ft_1lstclear(&start, del);
			return (0);
		}
		ft_1lstadd_back(&start, list);
		lst = lst->next;
	}
	return (start);
}
