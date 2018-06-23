/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lem_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:53:15 by lucien            #+#    #+#             */
/*   Updated: 2018/06/23 23:11:43 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*cpy_one_room(char *s1, char *s2)
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

void		add_room_in_soluc(t_map *m, char *soluc, char *s2)
{
	int		i;

	i = 0;
	while (s2[i] && s2[i] != '\n')
	{
		if (s2[i] == '-')
			break ;
		soluc[m->i] = s2[i];
		m->i++;
		i++;
	}
	soluc[m->i] = '-';
	m->i++;
	soluc[m->i] = '\0';
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
	ft_strcpy_char(dst, &src[i], 'L', c);
	return (dst);
}

int			remove_last_room(t_map *m)
{
	m->i -= 2;
	while (m->soluc[m->i] != '-')
	{
		if (m->soluc[m->i] == '\n')
			break ;
		m->i--;
	}
	if (m->i != 0)
		m->i++;
	return (m->i);
}

void		remove_last_solution(t_map *m)
{
	m->i = m->i - 2;
	while (m->i > 0)
	{
		if (m->soluc[m->i] == '\n')
			break ;
		m->i--;
	}
	m->soluc[m->i] = '\0';
}
