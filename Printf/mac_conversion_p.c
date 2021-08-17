/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_conversion_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:45:11 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/11 17:37:46 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	apply_flags(char *str, t_flags *flags)
{
	int	len;
	int	chars;

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
	uint64_t	ptr;
	char		*str;

	ptr = (uint64_t)va_arg(*list, void *);
	str = bin64_to_hex(ptr);
	(vars->nb_chars) += apply_flags(str, flags);
	free(str);
}
