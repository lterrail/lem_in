/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:13:14 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/26 15:49:10 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			init_room(t_room *room)
{
	room->name = NULL;
	room->branch = NULL;
	room->x = 0;
	room->y = 0;
	room->distance = -1;
	room->link = 0;
	room->i_branch = 0;
	room->occuped = 0;
	room->next = NULL;
}

static t_room		*parse_start_end(t_map *m, t_room *room)
{
	if (m->instruction == START_INSTRUCTION)
		m->start = room;
	else if (m->instruction == END_INSTRUCTION)
		m->end = room;
	m->instruction = 0;
	return (room);
}

static inline void	*ft_room_error(t_room *room, int *erno, int error)
{
	free(room->name);
	free(room);
	*erno = error;
	return (NULL);
}

static inline int	is_duplicate_name(t_map *m, t_room *room)
{
	t_room *elem;

	if (ft_strhas_char(room->name, '-'))
		return (NAME_ROOM_ERROR);
	elem = m->rooms;
	while (elem)
	{
		if (!ft_strcmp(elem->name, room->name))
			return (DUPLICATED_NAME);
		elem = elem->next;
	}
	return (E_SUCCESS);
}

t_room				*parse_room(t_map *m, char *line, int *erno, int error)
{
	t_room	*room;
	int		i;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	init_room(room);
	i = 0;
	if (line && *line == 'L')
		return (ft_room_error(room, erno, NAME_ROOM_ERROR));
	while (line[i] && line[i] != ' ')
		i++;
	if (!i || line[i] != ' ' || !(room->name = ft_strndup(line, i++)))
		return (ft_room_error(room, erno, NAME_ROOM_ERROR));
	if ((error = is_duplicate_name(m, room)) != 1)
		return (ft_room_error(room, erno, error));
	room->x = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i++] != ' ' || room->x < 0 || (room->y = ft_atoi(line + i)) < 0)
		return (ft_room_error(room, erno, PARSE_ROOM_ERROR));
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] != '\0' || line[i] == '\n')
		return (ft_room_error(room, erno, PARSE_ROOM_ERROR));
	return (parse_start_end(m, room));
}
