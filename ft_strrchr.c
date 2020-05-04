/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:17:46 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/04 11:52:35 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	if (!c)
		return ((char*)&s[ft_strlen(s)]);
	i = ft_strlen(s);
	ch = (char)c;
	while (--i >= 0)
		if (s[i] == ch)
			return ((char*)&s[i]);
	return (0);
}
