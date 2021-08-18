/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:16:15 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/18 16:02:49 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2lstadd_back(t_2list **alst, t_2list *new)
{
	if (!alst)
		return ;
	if (*alst)
	{
		new->prev = ft_2lstlast(*alst);
		ft_2lstlast(*alst)->next = new;
	}
	else
		*alst = new;
}
