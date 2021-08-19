/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2lstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:25:12 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/18 16:57:57 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_2lstadd_front(t_2list **alst, t_2list *new)
{
	ft_printf("1\n");
	new->next = *alst;
	ft_printf("2\n");
	if (*alst)
		(*alst)->prev = new;
	ft_printf("3\n");
	*alst = new;
	ft_printf("4\n");
}
