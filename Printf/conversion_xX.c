/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_xX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:18:18 by ocmarout          #+#    #+#             */
/*   Updated: 2021/07/22 15:35:57 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_precision(char *str, t_flags *flags, int len)
{
	int		chars;
	int		precision;

	chars = 0;
	precision = flags->precision;
	if (precision == 0 && *str == '0')
		return (0);
	if (flags->nb_sgn == '#' && flags->flag == 'x' && *str != '0')
		write(1, "0x", 2);
	if (flags->nb_sgn == '#' && flags->flag == 'X' && *str != '0')
		write(1, "0X", 2);
	while (precision > len)
	{
		write(1, "0", 1);
		chars++;
		precision--;
	}
	return (chars);
}

static int	apply_flags_part2(char *str, t_flags *flags, int len)
{
	int	chars;

	chars = 0;
	if (flags->left_justify)
		chars += apply_precision(str, flags, len);
	if (flags->left_justify)
		ft_putstr_fd(str, 1);
	if (flags->nb_sgn == '#' && *str != '0')
		chars += 2;
	if (flags->nb_sgn == '#' && *str != '0')
		flags->width -= 2;
	while (flags->width > len && flags->width > flags->precision)
	{
		write(1, &(flags->filler), 1);
		chars++;
		(flags->width)--;
	}
	if (!(flags->left_justify))
		chars += apply_precision(str, flags, len);
	if (!(flags->left_justify))
		ft_putstr_fd(str, 1);
	return (chars);
}

static int	apply_flags(char *str, t_flags *flags)
{
	int	len;
	int	chars;

	len = ft_strlen(str);
	chars = 0;
	if (flags->precision == 0 && *str == '0')
	{
		while ((flags->width)-- > 0)
		{
			write(1, " ", 1);
			chars++;
		}
		return (chars);
	}
	chars += apply_flags_part2(str, flags, len);
	return (chars + len);
}

void	print_hex(va_list *list, t_flags *flags, t_vars *vars)
{
	unsigned int	u;
	char			*str;

	str = 0;
	u = va_arg(*list, unsigned int);
	if (flags->flag == 'x')
		str = ft_utoa_base(u, "0123456789abcdef");
	else
		str = ft_utoa_base(u, "0123456789ABCDEF");
	(vars->nb_chars) += apply_flags(str, flags);
	free(str);
}
