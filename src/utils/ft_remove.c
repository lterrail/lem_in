/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:45:19 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/27 18:00:40 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void		remove_soluc(t_map *m, char *n_soluc, char *room)
{
	int		i_start;
	int		i_next;
	int		len;

	i_start = ft_int_strstr(n_soluc, room);
	while (i_start > 0 && m->soluc[i_start] != '\n')
		i_start--;
	if (i_start != 0)
		i_start += 1;
	i_next = i_start;
	while (m->soluc[i_next] != '\n')
		i_next++;
	i_next++;
	len = ft_strlen_char(m->soluc, '\n');
	ft_strcpy(&m->soluc[i_start], &m->soluc[i_next]);
	m->i -= len;
	next_solution(m);
}
