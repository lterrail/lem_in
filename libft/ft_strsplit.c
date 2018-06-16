/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:36:16 by lterrail          #+#    #+#             */
/*   Updated: 2018/04/11 17:44:29 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || s[i + 1] == '\0')
			words++;
		i++;
	}
	return (words);
}

static int		ft_count_letters(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		j++;
		i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i_mots;
	int		tot_mots;
	int		ligne;
	char	**tab;
	int		i;

	i = 0;
	i_mots = 0;
	if (!s)
		return (NULL);
	tot_mots = ft_count_words(s, c);
	if (!(tab = malloc(sizeof(char *) * (tot_mots + 1))))
		return (0);
	while (i_mots < tot_mots)
	{
		while (s[i] == c)
			i++;
		tab[i_mots] = malloc(sizeof(char) * (ft_count_letters(s + i, c) + 1));
		ligne = 0;
		while (s[i] && s[i] != c)
			tab[i_mots][ligne++] = s[i++];
		tab[i_mots++][ligne] = '\0';
	}
	tab[i_mots] = 0;
	return (tab);
}
