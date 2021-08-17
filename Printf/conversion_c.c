/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:16:44 by ocmarout          #+#    #+#             */
/*   Updated: 2021/07/12 19:42:03 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_zero(t_flags *flags)
{
	int	chars;

	chars = 0;
	while (flags->width > 0)
	{
		write(1, " ", 1);
		chars++;
		(flags->width)--;
	}
	return (chars);
}

static int	apply_precision(char c, t_flags *flags)
{
	int	chars;

	chars = 0;
	while (flags->precision > chars)
	{
		write(1, &c, 1);
		chars++;
	}
	return (chars);
}

static int	apply_flags(char c, t_flags *flags)
{
	int	chars;

	chars = 0;
	if (flags->precision == 0)
		return (chars + apply_zero(flags));
	if (flags->precision < 0)
		flags->precision = 1;
	if (flags->left_justify)
		chars += apply_precision(c, flags);
	while (flags->width > 1 || flags->width > flags->precision)
	{
		write(1, " ", 1);
		chars++;
		(flags->width)--;
	}
	if (!(flags->left_justify))
		chars += apply_precision(c, flags);
	return (chars);
}

void	print_char(va_list *list, t_flags *flags, t_vars *vars)
{
	char	c;

	if (flags->flag == '%')
		c = '%';
	else
		c = va_arg(*list, int);
	(vars->nb_chars) += apply_flags(c, flags);
}
