/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 00:14:19 by ocmarout          #+#    #+#             */
/*   Updated: 2021/07/22 18:47:19 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	find_index(t_vars *vars, char const *f, t_flags *flags)
{
	int		i;

	i = 0;
	while (i < NB_FLAGS && vars->flags[i] != f[vars->i])
		i++;
	if (i < NB_FLAGS)
		flags->flag = vars->flags[i];
	if (!((!(i % NB_FLAGS)) & i))
		return (i);
	else
		return (-1);
}

void	zero_flags(t_flags *flags)
{
	flags->width = 0;
	flags->precision = -1;
	flags->left_justify = 0;
	flags->filler = ' ';
	flags->nb_sgn = '\0';
	flags->start = '\0';
	flags->flag = 0;
}

void	set_vars(t_vars *vars)
{
	vars->i = 0;
	vars->index = 0;
	vars->nb_chars = 0;
	vars->flags[0] = 'd';
	vars->tab[0] = print_nbr;
	vars->flags[1] = 's';
	vars->tab[1] = print_str;
	vars->flags[2] = 'p';
	vars->tab[2] = print_ptr;
	vars->flags[3] = 'c';
	vars->tab[3] = print_char;
	vars->flags[4] = 'i';
	vars->tab[4] = print_nbr;
	vars->flags[5] = 'u';
	vars->tab[5] = print_nbr;
	vars->flags[6] = 'x';
	vars->tab[6] = print_hex;
	vars->flags[7] = 'X';
	vars->tab[7] = print_hex;
	vars->flags[8] = '%';
	vars->tab[8] = print_char;
}

int	ft_printf(char const *f, ...)
{
	va_list	args;
	t_vars	vars;
	t_flags	flags;

	va_start(args, f);
	set_vars(&vars);
	zero_flags(&flags);
	while (f[vars.i])
	{
		if (f[vars.i] == '%')
		{
			(vars.i)++;
			vars.index = parser(f, &args, &vars, &flags);
			if (vars.index != -1)
				vars.tab[vars.index](&args, &flags, &vars);
		}
		else
		{
			(vars.nb_chars)++;
			write(1, &f[vars.i], 1);
		}
		(vars.i)++;
	}
	va_end(args);
	return (vars.nb_chars);
}
