/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_conversion_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:45:11 by ocmarout          #+#    #+#             */
/*   Updated: 2021/07/15 16:56:30 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	zero_flag(t_flags *flags)
{
	int		len;
	int		chars;
	char	*str;

	len = 5;
	chars = 0;
	str = ft_strdup("(nil)");
	if (flags->left_justify)
		ft_putstr_fd(str, 1);
	while (flags->width > len)
	{
		write(1, " ", 1);
		chars++;
		(flags->width)--;
	}
	if (!(flags->left_justify))
		ft_putstr_fd(str, 1);
	free(str);
	return (len + chars);
}

static int	apply_flags(char *str, t_flags *flags)
{
	int	len;
	int	chars;

	if (ft_strlen(str) == 1 && str[0] == '0')
		return (zero_flag(flags));
	len = ft_strlen(str) + 2;
	chars = 0;
	if (flags->left_justify)
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(str, 1);
	}
	while (flags->width > len)
	{
		write(1, " ", 1);
		chars++;
		(flags->width)--;
	}
	if (!(flags->left_justify))
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(str, 1);
	}
	return (len + chars);
}

void	print_ptr(va_list *list, t_flags *flags, t_vars *vars)
{
	uintptr_t	ptr;
	char		*str;

	ptr = (uintptr_t)va_arg(*list, void *);
	str = ft_utoa_base(ptr, "0123456789abcdef");
	(vars->nb_chars) += apply_flags(str, flags);
	free(str);
}
