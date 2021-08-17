/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 23:57:23 by ocmarout          #+#    #+#             */
/*   Updated: 2021/07/22 18:48:24 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

# define NB_FLAGS 9

typedef struct s_flags
{
	int		width;
	int		precision;
	int		left_justify;
	char	filler;
	char	nb_sgn;
	char	start;
	char	flag;
}				t_flags;

typedef struct s_vars
{
	int		i;
	int		index;
	int		nb_chars;
	char	flags[NB_FLAGS];
	void	(*tab[NB_FLAGS])(va_list *, t_flags *, struct s_vars *);
}				t_vars;

int				ft_printf(char const *f, ...);
int				parser(char const *f, va_list *args, t_vars *vars,
					t_flags *flags);
int				find_index(t_vars *vars, char const *f, t_flags *flags);
void			print_str(va_list *list, t_flags *flags, t_vars *vars);
void			print_char(va_list *list, t_flags *flags, t_vars *vars);
void			print_nbr(va_list *list, t_flags *flags, t_vars *vars);
void			print_hex(va_list *list, t_flags *flags, t_vars *vars);
void			print_ptr(va_list *list, t_flags *flags, t_vars *vars);
void			set_vars(t_vars *vars);
void			zero_flags(t_flags *flags);

#endif
