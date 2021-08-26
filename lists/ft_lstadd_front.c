/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:25:12 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/26 12:14:35 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	ft_printf("add front IN\n");
	new->next = *alst;
	ft_printf("1\n");
	if (*alst)
		(*alst)->prev = new;
	ft_printf("2\n");
	*alst = new;
	ft_printf("add front OUT\n");
}
