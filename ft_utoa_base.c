/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:20:21 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/07 15:20:15 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_write_str(int len, unsigned int mod, unsigned int nb,
		const char *base)
{
	int		i;
	int		len_base;
	char	*str;

	i = 0;
	len_base = ft_strlen(base);
	if (!(str = malloc(sizeof(char) * len)))
		return (0);
	while (mod > 0)
	{
		str[i++] = base[nb / mod];
		nb %= mod;
		mod /= len_base;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_utoa_base(unsigned int n, const char *base)
{
	int				i;
	int				len;
	int				len_base;
	long			mod;

	len_base = ft_check_base(base);
	if (len_base < 2)
		return (0);
	i = 0;
	mod = 1;
	len = 2;
	while (mod * len_base <= n)
	{
		len++;
		mod *= len_base;
	}
	return (ft_write_str(len, mod, n, base));
}
