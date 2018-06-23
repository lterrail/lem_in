/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:15:56 by lucien            #+#    #+#             */
/*   Updated: 2018/06/23 13:26:20 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_new_room(t_map *m)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strstr_char(m->links, m->next_room);
	while (tmp[i] && tmp[i] != '\n')
	{
		if (tmp[i] == '-')
			break ;
		m->next_room[i] = tmp[i];
		i++;
	}
	m->next_room[i] = '\0';
}

void		delete_link(t_map *m, char *s2)
{
	int		i_clear;
	int		i_next;

	i_clear = ft_int_strstr(m->links, s2);
	if (m->loop == 0)
		set_new_room(m);
	i_next = i_clear;
	while (m->links[i_next] && m->links[i_next] != '\n')
		i_next++;
	if (m->links[i_next] == '\0')
	{
		m->links[i_clear] = '\0';
		return ;
	}
	i_next += 1;
	while (m->links[i_next])
	{
		m->links[i_clear] = m->links[i_next];
		i_clear++;
		i_next++;
	}
	m->links[i_clear] = '\0';
}
