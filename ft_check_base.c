/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:10:08 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/07 14:39:39 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_base(const char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (ft_strchr(base + i + 1, base[i]))
			return (-1);
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}
