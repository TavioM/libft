/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:13:39 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/19 17:40:12 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2lstdelone(t_2list *lst)
{
	if (lst->prev)
		lst->prev->next = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	free(lst->data);
	free(lst);
}
