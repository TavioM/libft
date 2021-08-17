/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:30:10 by ocmarout          #+#    #+#             */
/*   Updated: 2021/07/22 18:48:56 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	parse_filler(char const *f, t_vars *vars, t_flags *flags)
{
	if (f[vars->i] == '0' && !(flags->left_justify))
	{
		(vars->i)++;
		flags->filler = '0';
	}
	if (f[vars->i] == '-')
	{
		(vars->i)++;
		flags->left_justify = 1;
		flags->filler = ' ';
	}
}

static void	parse_bonus(char const *f, t_vars *vars, t_flags *flags)
{
	if (f[vars->i] == '#')
	{
		flags->nb_sgn = '#';
		(vars->i)++;
	}
	if (f[vars->i] == '+')
	{
		flags->start = '+';
		(vars->i)++;
	}
	if (f[vars->i] == ' ')
	{
		if (flags->start != '+')
			flags->start = ' ';
		(vars->i)++;
	}
}

static void	parse_width(char const *f, t_vars *vars, t_flags *flags,
		va_list *args)
{
	if (f[vars->i] == '*')
	{
		flags->width = va_arg(*args, int);
		(vars->i)++;
	}
	else
	{
		flags->width = ft_atoi(f + vars->i);
		while (ft_isdigit(f[vars->i]))
			(vars->i)++;
	}
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->filler = ' ';
		flags->left_justify = 1;
	}
}

static void	parse_preci(char const *f, t_vars *vars, t_flags *flags,
		va_list *args)
{
	if (f[vars->i] == '.')
	{
		(vars->i)++;
		if (f[vars->i] == '*')
		{
			flags->precision = va_arg(*args, int);
			(vars->i)++;
		}
		else
		{
			flags->precision = ft_atoi(f + vars->i);
			while (f[vars->i] >= '0' && f[vars->i] <= '9')
				(vars->i)++;
		}
		if (flags->precision >= 0)
			flags->filler = ' ';
	}
}

int	parser(char const *f, va_list *args, t_vars *vars, t_flags *flags)
{
	int	index;

	zero_flags(flags);
	index = find_index(vars, f, flags);
	while (index == -1)
	{
		parse_filler(f, vars, flags);
		parse_bonus(f, vars, flags);
		parse_width(f, vars, flags, args);
		parse_preci(f, vars, flags, args);
		index = find_index(vars, f, flags);
	}
	return (index);
}
