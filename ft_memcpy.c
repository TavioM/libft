/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:38:30 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/04 11:48:38 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dt;
	const char	*sc;

	if (dst == src)
		return (dst);
	dt = dst;
	sc = src;
	while (n-- != 0)
		*(dt + n) = *(sc + n);
	return (dst);
}
