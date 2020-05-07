/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:27:10 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/07 11:58:02 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_write_str(int len, unsigned int mod, unsigned int nb)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * len)))
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

char		*ft_utoa(unsigned int n)
{
	int				i;
	int				len;
	long			mod;

	i = 0;
	mod = 1;
	len = 2;
	while (mod * 10 <= n)
	{
		len++;
		mod *= 10;
	}
	return (ft_write_str(len, mod, n));
}
