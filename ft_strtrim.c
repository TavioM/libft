/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:59:00 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/04 12:06:16 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	int	i;

	if (!s || !set)
		return (0);
	while (*s && ft_strchr(set, *s))
		s++;
	i = ft_strlen(s) - 1;
	while (i >= 0 && s[i] && ft_strchr(set, s[i]))
		i--;
	return (ft_substr(s, 0, i + 1));
}
