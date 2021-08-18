/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:25:12 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/18 16:04:21 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2lstadd_front(t_2list **alst, t_2list *new)
{
	new->next = *alst;
	if (*alst)
		(*alst)->prev = new;
	*alst = new;
}
