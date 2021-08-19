/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:34:23 by ocmarout          #+#    #+#             */
/*   Updated: 2021/08/19 12:32:37 by ocmarout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char **tab, int i)
{
	while (i >= 0)
		free(tab[i--]);
	free(tab);
	return (0);
}

static int	ft_fill_tab(char const *s, char c, char **tab, int n)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	k = 0;
	while (i < n)
	{
		j = 0;
		while (s[k] && (s[k] == c))
			k++;
		l = k;
		while (s[l] && s[l] != c)
			l++;
		tab[i] = malloc(sizeof(char) * (l - k + 1));
		if (!(tab[i]))
			return (ft_free(tab, i - 1));
		while (k < l)
			tab[i][j++] = s[k++];
		tab[i++][j] = 0;
	}
	tab[i] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		n;
	char	**tab;

	i = 0;
	j = 1;
	n = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] && s[i] != c && j)
			n++;
		if (s[i] && s[i] != c && j)
			j = 0;
		else if (s[i] && s[i] == c && !j)
			j = 1;
		i++;
	}
	tab = malloc(sizeof(char *) * (n + 1));
	if (!tab)
		return (0);
	ft_fill_tab(s, c, tab, n);
	return (tab);
}
