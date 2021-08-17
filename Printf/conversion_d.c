/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:18:18 by ocmarout          #+#    #+#             */
/*   Updated: 2021/07/22 18:42:00 by ocmarout         ###   ########.fr       */
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
	while (precision > len)
	{
		write(1, "0", 1);
		chars++;
		(precision)--;
	}
	return (chars);
}

static int	apply_flags_part2(char *str, t_flags *flags, int len)
{
	int	chars;

	chars = 0;
	str++;
	(flags->precision)++;
	if (flags->left_justify || flags->filler == '0')
		write(1, "-", 1);
	if (flags->left_justify)
		chars += apply_precision(str, flags, len);
	if (flags->left_justify)
		ft_putstr_fd(str, 1);
	while (flags->width > len && flags->width > flags->precision)
	{
		write(1, &(flags->filler), 1);
		chars++;
		(flags->width)--;
	}
	if (!(flags->filler == '0') && !(flags->left_justify))
		write(1, "-", 1);
	if (!(flags->left_justify))
		chars += apply_precision(str, flags, len);
	if (!(flags->left_justify))
		ft_putstr_fd(str, 1);
	return (chars);
}

static int	apply_flags_part3(char *str, t_flags *flags, int len)
{
	int	chars;

	chars = (flags->start == '+');
	flags->width -= (flags->start == '+');
	if (flags->start == '+' && flags->left_justify)
		write(1, "+", 1);
	if (flags->left_justify)
		chars += apply_precision(str, flags, len);
	if (flags->left_justify)
		ft_putstr_fd(str, 1);
	while (flags->width > len && flags->width > flags->precision)
	{
		write(1, &(flags->filler), 1);
		chars++;
		(flags->width)--;
	}
	if (flags->start == '+' && !(flags->left_justify))
		write(1, "+", 1);
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
	chars = (flags->precision == 0) * (*str == '0') * (flags->start != 0);
	(flags->width) = (flags->width) - chars;
	if (flags->precision == 0 && *str == '0')
	{
		if (flags->start && flags->left_justify)
			write(1, &(flags->start), 1);
		chars += flags->width * (flags->width > 0);
		while ((flags->width)-- > 0)
			write(1, " ", 1);
		if (flags->start && !(flags->left_justify))
			write(1, &(flags->start), 1);
		return (chars);
	}
	if (str[0] == '-')
		return (chars + len + apply_flags_part2(str, flags, len));
	flags->width -= flags->start == ' ';
	if (flags->start == ' ')
		write(1, " ", 1);
	chars += (flags->start == ' ') + apply_flags_part3(str, flags, len);
	return (chars + len);
}

void	print_nbr(va_list *list, t_flags *flags, t_vars *vars)
{
	int				d;
	unsigned int	u;
	char			*str;

	str = 0;
	if (flags->flag == 'd' || flags->flag == 'i')
		d = va_arg(*list, int);
	else
		u = va_arg(*list, unsigned int);
	if (flags->flag == 'd' || flags->flag == 'i')
		str = ft_itoa(d);
	else if (flags->flag == 'u')
		str = ft_utoa(u);
	(vars->nb_chars) += apply_flags(str, flags);
	free(str);
}
