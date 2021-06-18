/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:20:21 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/07 15:48:07 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_write_str(int len, unsigned int mod, unsigned int nb,
		char const *base)
{
	int		i;
	int		sign;
	int		len_base;
	char	*str;

	i = 0;
	sign = 1;
	if (len < 0)
	{
		sign = -1;
		len *= -1;
	}
	len_base = ft_strlen(base);
	str = malloc(sizeof(char) * len);
	if (!str)
		return (0);
	if (sign == -1)
		str[i++] = '-';
	while (mod > 0)
	{
		str[i++] = base[nb / mod];
		nb %= mod;
		mod /= len_base;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_base(int n, char const *base)
{
	int				i;
	int				len;
	int				len_base;
	long			mod;
	unsigned int	nb;

	len_base = ft_check_base(base);
	if (len_base < 2)
		return (0);
	i = 0;
	mod = 1;
	len = 2;
	if (n < 0)
		len++;
	nb = (unsigned)n;
	if (n < 0)
		nb = (unsigned)n * -1;
	while (mod * len_base <= nb)
	{
		len++;
		mod *= len_base;
	}
	if (n < 0)
		len *= -1;
	return (ft_write_str(len, mod, nb, base));
}
