/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:20:04 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/04 11:53:39 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*list;

	if (!lst || !f)
		return (0);
	if (!(start = ft_lstnew(f(lst->content))))
		return (0);
	lst = lst->next;
	while (lst)
	{
		if (!(list = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&start, del);
			return (0);
		}
		ft_lstadd_back(&start, list);
		lst = lst->next;
	}
	return (start);
}
