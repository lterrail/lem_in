/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:24:25 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/26 16:35:38 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_ant_per_turn(t_map *m, int ant_per_turn)
{
	if (m->ant_in < m->ant_per_turn)
	{
		ant_per_turn += m->ant_in;
		m->ant_in = 0;
	}
	else if (m->ant_in >= m->ant_per_turn && ant_per_turn < m->max_ant_per_turn)
	{
		m->ant_in -= m->ant_per_turn;
		ant_per_turn += m->ant_per_turn;
	}
	return (ant_per_turn);
}

static char		*next_room(t_room *room, t_ant *ant, int distance)
{
	int		i;
	t_room	*tmp;

	i = 0;
	tmp = room;
	tmp->occuped = 0;
	while (tmp->link > i)
	{
		if (distance >= tmp->branch[i]->distance && tmp->branch[i]->occuped == 0
			&& tmp->branch[i] != ant->to)
			distance = tmp->branch[i]->distance;
		i++;
	}
	tmp->i_branch = 0;
	tmp = room;
	if (distance == INT_MAX)
		return (NULL);
	else
	{
		while (distance != tmp->branch[tmp->i_branch]->distance
			|| tmp->branch[tmp->i_branch]->occuped == 1
			|| tmp->branch[tmp->i_branch] == ant->to)
			tmp->i_branch++;
	}
	return (tmp->branch[tmp->i_branch]->name);
}

static void		if_ant_out(t_map *m, t_ant *tmp, char *name)
{
	if (!(ft_strcmp(name, m->end->name)))
	{
		m->ant_out++;
		tmp->room->occuped = 0;
		tmp->arrived = 1;
	}
	else
	{
		tmp->to = tmp->room;
		tmp->room->branch[tmp->room->i_branch]->occuped = 1;
	}
	tmp->room = tmp->room->branch[tmp->room->i_branch];
}

extern void		print_ant(t_map *m, int ants, int ant_per_turn, int tot_ants)
{
	t_ant	*tmp;
	char	*name;

	tmp = m->ants;
	while (tot_ants > m->ant_out)
	{
		while (tmp && (++ants < ant_per_turn) && tot_ants > m->ant_out)
		{
			while (tmp->next && tmp->arrived == 1)
				tmp = tmp->next;
			if (!tmp->next && tmp->arrived == 1)
				break ;
			if ((name = next_room(tmp->room, tmp, INT_MAX)) != NULL)
			{
				ft_printf("L%d-%s", tmp->id, name);
				tmp->next && ants + 1 != ant_per_turn
				&& tot_ants > m->ant_out + 1 ? ft_printf(" ") : ft_printf("\n");
				if_ant_out(m, tmp, name);
			}
			tmp = tmp->next;
		}
		ants = -1;
		tmp = m->ants;
		ant_per_turn = ft_ant_per_turn(m, ant_per_turn);
	}
}
