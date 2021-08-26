/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:16:15 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/26 12:13:02 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!alst)
		return ;
	if (*alst)
	{
		new->prev = ft_lstlast(*alst);
		ft_lstlast(*alst)->next = new;
	}
	else
		*alst = new;
}
