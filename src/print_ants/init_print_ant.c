/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_print_ant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:16:56 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/26 16:35:13 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	ft_create_list_ants(t_ant **begin_ant, t_ant *new)
{
	t_ant	*begin;

	begin = *begin_ant;
	if (begin)
	{
		while (begin->next)
			begin = begin->next;
		begin->next = new;
		new->next = NULL;
	}
	else
	{
		*begin_ant = new;
		new->next = NULL;
	}
}

static void			ft_create_ants(t_map *m)
{
	int		i;
	t_ant	*begin;
	t_ant	*ant;

	i = 0;
	begin = NULL;
	while (++i <= m->ant_in)
	{
		if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
			return ;
		ant->id = i;
		ant->room = m->start;
		ant->to = NULL;
		ant->arrived = 0;
		ant->next = NULL;
		ft_create_list_ants(&begin, ant);
	}
	m->ants = begin;
}

static void			init_ant_per_turn(t_map *m)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (m->start->link > i)
	{
		if (m->start->branch[i]->occuped == 0)
			nb++;
		i++;
	}
	m->ant_per_turn = nb;
	i = 0;
	nb = 0;
	while (m->end->link > i)
	{
		if (m->end->branch[i]->occuped == 0)
			nb++;
		i++;
	}
	if (nb < m->ant_per_turn)
		m->ant_per_turn = nb;
	m->max_ant_per_turn = m->ant_per_turn * m->start->distance;
}

extern void			init_print_ants(t_map *m)
{
	int		i;

	i = 0;
	ft_create_ants(m);
	init_ant_per_turn(m);
	while (m->start->link > i)
	{
		if (!ft_strcmp(m->start->branch[i]->name, m->end->name))
			m->ant_per_turn = m->ant_in;
		i++;
	}
	print_ant(m, -1, m->ant_per_turn, m->ant_in);
}
