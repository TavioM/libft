/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:34:56 by ocmarout          #+#    #+#             */
/*   Updated: 2020/05/07 15:48:22 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (str)
		return (0);
	str = ft_strcpy(str, src);
	return (str);
}
