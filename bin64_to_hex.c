/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin64_to_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:14:56 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/11 17:38:15 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	remove_starting_zeros(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] == '0' && str[j + 1] != 0)
		j++;
	while (str[i])
	{
		str[i] = str[i + j];
		i++;
	}
}

char	*bin64_to_hex(uint64_t nb)
{
	int		i;
	int		j;
	char	*hex;

	j = 0;
	hex = malloc(sizeof(char) * (16 + 1));
	if (!hex)
		return (0);
	hex[16] = 0;
	while (j < 16)
	{
		i = 1;
		hex[15 - j] = '0';
		while (i <= 8)
		{
			if (nb & 1)
				hex[15 - j] += i;
			nb = nb >> 1;
			i += i;
		}
		hex[15 - j] += (hex[15 - j] > '9') * 39;
		j++;
	}
	remove_starting_zeros(hex);
	return (hex);
}
