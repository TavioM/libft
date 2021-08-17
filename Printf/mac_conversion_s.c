/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_conversion_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:15:38 by ocmarout          #+#    #+#             */
/*   Updated: 2021/07/15 17:21:10 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_precision(char *str, t_flags *flags)
{
	int		chars;

	chars = 0;
	while (flags->precision > chars && *str)
	{
		write(1, &(*str), 1);
		chars++;
		str++;
	}
	return (chars);
}

static int	zero_precision(t_flags *flags)
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

static int	apply_flags(char *str, t_flags *flags)
{
	int	len;
	int	chars;

	len = ft_strlen(str);
	chars = 0;
	if (flags->precision == 0)
		return (zero_precision(flags));
	if (flags->precision < 0)
		flags->precision = len;
	if (flags->left_justify)
		chars += apply_precision(str, flags);
	while (flags->width > len || flags->width > flags->precision)
	{
		write(1, " ", 1);
		chars++;
		(flags->width)--;
	}
	if (!(flags->left_justify))
		chars += apply_precision(str, flags);
	return (chars);
}

void	print_str(va_list *list, t_flags *flags, t_vars *vars)
{
	char	*str;

	str = va_arg(*list, char *);
	if (str == 0)
		(vars->nb_chars) += apply_flags("(null)", flags);
	else
		(vars->nb_chars) += apply_flags(str, flags);
}
