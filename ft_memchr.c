/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:29:32 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/04 11:53:16 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	unsigned int	i;
	unsigned char	ch;

	i = 0;
	str = (char*)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if ((unsigned char)str[i] == ch)
			return ((void*)&s[i]);
		i++;
	}
	return (0);
}
