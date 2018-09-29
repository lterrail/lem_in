/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:49:19 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/25 20:34:34 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				free_ants(t_ant *ant)
{
	t_ant		*tmp;

	while (ant)
	{
		tmp = ant;
		ant = ant->next;
		free(tmp);
		tmp = NULL;
	}
}

static inline void	free_rooms(t_room *room)
{
	t_room		*tmp;

	while (room)
	{
		tmp = room;
		room = room->next;
		free(tmp->name);
		free(tmp->branch);
		free(tmp);
		tmp = NULL;
	}
}

void				free_all(t_map *m)
{
	free_rooms(m->rooms);
	free(m->std);
	free(m);
}
