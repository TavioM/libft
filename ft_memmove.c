/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:10:52 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/04 12:06:41 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*dt;
	unsigned char	*sc;

	dt = (unsigned char *)dst;
	sc = (unsigned char *)src;
	i = 0;
	if (dt > sc)
		while (i < len)
		{
			i++;
			dt[len - i] = sc[len - i];
		}
	else if (dt < sc)
		while (i < len)
		{
			dt[i] = sc[i];
			i++;
		}
	return (dst);
}
