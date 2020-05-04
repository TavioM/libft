/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:01:22 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/04 11:51:46 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = -1;
	ch = (char)c;
	if (!c)
		return ((char*)&(s[ft_strlen(s)]));
	while (s[++i])
		if (s[i] == ch)
			return ((char*)&s[i]);
	return (0);
}
