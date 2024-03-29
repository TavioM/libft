/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:27:10 by ocmarout          #+#    #+#             */
/*   Updated: 2021/10/07 17:12:28 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_write_str(int len, unsigned int mod, unsigned int nb)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (0);
	while (mod > 0)
	{
		str[i++] = nb / mod + '0';
		nb %= mod;
		mod /= 10;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	int				len;
	long			mod;

	mod = 1;
	len = 2;
	while (mod * 10 <= n)
	{
		len++;
		mod *= 10;
	}
	return (ft_write_str(len, mod, n));
}
