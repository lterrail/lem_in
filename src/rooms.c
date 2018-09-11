/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:18:10 by lucien            #+#    #+#             */
/*   Updated: 2018/08/07 17:04:41 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			room_link(t_room *one, t_room *two, int flag)
{
	t_room	**new;
	int		i;

	i = 0;
	printf("one->linked %d\n", one->linked);
	printf("two->linked %d\n", two->linked);
	if (!(new = malloc(sizeof(t_room *) * (one->linked + 1))))
		return (E_ERROR);
	while (i < one->linked)
	{
		new[i] = one->branch[i];
		i++;
	}
	if (one->linked)
		free(one->branch);
	one->branch = new;
	new[i] = two;
	one->linked++;
	if (!flag)
		return (room_link(two, one, 1));
	return (E_SUCCESS);
}

int			room_add(t_map *m, char *name, t_coord *c)
{
	t_room	*tmp;
	t_room	*new;

	tmp = m->rooms;
	if (!(new = malloc(sizeof(t_room))))
		return (E_ERROR);
	new->name = name;
	printf("name %s\n", new->name);
	new->linked = 0;
	new->branch = NULL;
	new->distance = -1;
	new->next = NULL;
	new->x = c->x;
	new->y = c->y;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!tmp)
		m->rooms = new;
	else
		tmp->next = new;
	if (m->instruction == START_INSTRUCTION)
		m->start = new;
	else if (m->instruction == END_INSTRUCTION)
		m->end = new;
	m->instruction = NO_INSTRUCTION;
	return (E_SUCCESS);
}
