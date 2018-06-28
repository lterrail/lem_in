/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:53:15 by lucien            #+#    #+#             */
/*   Updated: 2018/06/28 13:21:56 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*cpy_room(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s2[i] && s2[i] != '\n')
	{
		if (s2[i] == '-')
			break ;
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char		*cpy_last_soluc_room(t_map *m, char *dst, char *src, char c)
{
	int		i;

	i = m->i - 2;
	while (i > 0 && src[i] != c)
	{
		if (src[i] == '\n')
			break ;
		i--;
	}
	if (i != 0)
		i += 1;
	ft_strcpy_char(dst, &src[i], c);
	return (dst);
}

char		*cpy_soluc(t_map *m, int nb)
{
	int		i;
	char	*tmp;

	i = m->i - 2;
	if (nb == -1)
	{
		while (i > 0 && m->soluc[i] != '\n')
			i--;
		if (i != 0)
			i += 1;
		return (&m->soluc[i]);
	}
	i = 0;
	tmp = ft_strnew(m->len);
	while (nb != 0)
	{
		while (m->soluc[i] != '\n')
			i++;
		i++;
		nb--;
	}
	return (ft_strcpy_char(tmp, &m->soluc[i], '\n'));
}
