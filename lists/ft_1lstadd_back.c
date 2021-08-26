/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:50:10 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/26 11:52:39 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_1lstadd_back(t_1list **alst, t_1list *new)
{
	if (!alst)
		return ;
	if (*alst)
		ft_1lstlast(*alst)->next = new;
	else
		*alst = new;
}
