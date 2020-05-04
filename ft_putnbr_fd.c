/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:57:57 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/04 11:38:58 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int mod;

	mod = 1000000000;
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
	}
	while (mod > nb)
		mod /= 10;
	if (nb == 0)
		ft_putchar_fd('0', fd);
	while (mod > 0)
	{
		ft_putchar_fd(nb / mod + '0', fd);
		nb %= mod;
		mod /= 10;
	}
}
