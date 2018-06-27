/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:15:56 by lucien            #+#    #+#             */
/*   Updated: 2018/06/27 17:43:26 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delete_link(t_map *m, char *room)
{
	int		i_clear;
	int		i_next;
	int		len;

	len = ft_strlen_char(room, '-');
	room[len] = '\0';
	i_clear = ft_int_strstr(m->links, room);
	if (m->loop == 0)
		cpy_room(m->next_room, ft_strstr_char(m->links, m->next_room));
	i_next = i_clear;
	while (m->links[i_next] && m->links[i_next] != '\n')
		i_next++;
	if (m->links[i_next] == '\0')
	{
		m->links[i_clear] = '\0';
		return ;
	}
	i_next += 1;
	ft_strcpy(&m->links[i_clear], &m->links[i_next]);
}
