/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:19:11 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/07 15:49:57 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dt;
	unsigned char	*sc;

	if (dst == src)
		return (dst);
	i = 0;
	dt = (unsigned char*)dst;
	sc = (unsigned char*)src;
	while (i < n)
	{
		dt[i] = sc[i];
		if (dt[i] == (unsigned char)c)
			return (&dt[i + 1]);
		i++;
	}
	return (0);
}
