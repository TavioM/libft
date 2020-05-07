/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:20:21 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/07 14:45:02 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_write_str(int len, unsigned int mod, unsigned int nb,
		const char *base)
{
	int		i;
	int		sign;
	int		len_base;
	char	*str;

	i = 0;
	sign = len < 0 ? -1 : 1;
	len = len < 0 ? len * -1 : len;
	len_base = ft_strlen(base);
	if (!(str = malloc(sizeof(char) * len)))
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

char		*ft_itoa_base(int n, const char *base)
{
	int				i;
	int				len;
	int				len_base;
	long			mod;
	unsigned int	nb;

	len_base = ft_check_base(base);
	i = 0;
	mod = 1;
	len = n < 0 ? 3 : 2;
	nb = n < 0 ? (unsigned)n * -1 : (unsigned)n;
	while (mod * len_base <= nb)
	{
		len++;
		mod *= len_base;
	}
	len = n < 0 ? len * -1 : len;
	return (ft_write_str(len, mod, nb, base));
}
