/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 11:30:16 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/26 16:35:31 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

extern int			find_distance(t_room *room, int distance,
					char *start, char *end)
{
	int		i;

	i = 0;
	if (room->link == 1 && (ft_strcmp(room->name, start)
	&& ft_strcmp(room->name, end)))
	{
		room->occuped = 1;
		if (room->branch[0]->link == 2
		&& (ft_strcmp(room->branch[0]->name, start)
		&& ft_strcmp(room->branch[0]->name, end)))
			room->branch[0]->link = 1;
	}
	if (room->distance == -1 || room->distance > distance)
		room->distance = distance;
	else
		return (E_SUCCESS);
	while (i < room->link)
	{
		find_distance(room->branch[i], distance + 1, start, end);
		i++;
	}
	return (E_SUCCESS);
}
