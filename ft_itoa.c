/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:27:10 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/04 12:05:29 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_write_str(int len, unsigned int mod, unsigned int nb)
{
	int		i;
	int		sign;
	char	*str;

	i = 0;
	sign = len < 0 ? -1 : 1;
	len = len < 0 ? len * -1 : len;
	if (!(str = malloc(sizeof(char) * len)))
		return (0);
	if (sign == -1)
		str[i++] = '-';
	while (mod > 0)
	{
		str[i++] = nb / mod + '0';
		nb %= mod;
		mod /= 10;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int				i;
	int				len;
	long			mod;
	unsigned int	nb;

	i = 0;
	mod = 1;
	len = n < 0 ? 3 : 2;
	nb = n < 0 ? (unsigned)n * -1 : (unsigned)n;
	while (mod * 10 <= nb)
	{
		len++;
		mod *= 10;
	}
	len = n < 0 ? len * -1 : len;
	return (ft_write_str(len, mod, nb));
}
