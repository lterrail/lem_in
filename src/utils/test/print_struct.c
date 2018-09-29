/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:30:48 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/26 15:49:10 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

extern void		print_rooms(t_room *begin)
{
	t_room	*elem;
	int		i;

	if (!begin)
		return ;
	elem = begin;
	while (elem)
	{
		i = -1;
		ft_printf("\n{lmag}---- ROOMS ---- {def}\n");
		ft_printf("name: {lcyan}%s{def}\n", elem->name);
		ft_printf("nb_link: {lcyan}%d{def}\n", elem->link);
		ft_printf("distance: {lcyan}%d{def}\n", elem->distance);
		ft_printf("occuped: {lcyan}%d{def}\n", elem->occuped);
		while (++i < elem->link)
			ft_printf("link[%d]: %s\n", i, elem->branch[i]->name);
		elem = elem->next;
	}
}

extern void		print_map(t_map *map)
{
	ft_printf("\n{lred}---- MAP ---- {def}\n");
	ft_printf("\n{lred}---- START ---- {def}\n");
	ft_printf("name: {lcyan}%s{def}\n", map->start->name);
	ft_printf("x[{lcyan}%d{def}] - y[{lcyan}%d{def}]\n",
		map->start->x, map->start->y);
	ft_printf("nb_link: {lcyan}%d{def}\n", map->start->link);
	ft_printf("distance: {lcyan}%d{def}\n", map->start->distance);
	ft_printf("\n{lred}---- END ---- {def}\n");
	ft_printf("name: {lcyan}%s{def}\n", map->end->name);
	ft_printf("x[{lcyan}%d{def}] - y[{lcyan}%d{def}]\n",
		map->end->x, map->end->y);
	ft_printf("nb_link: {lcyan}%d{def}\n", map->end->link);
	ft_printf("distance s->e: {lcyan}%d{def}\n", map->end->distance);
}

extern void		print_ants(t_ant *ants)
{
	t_ant *elem;

	if (!ants)
		return ;
	elem = ants;
	while (elem)
	{
		ft_printf("\n{lblue}---- ANTS ---- {def}\n");
		ft_printf("id: {lcyan}%d{def}\n", elem->id);
		ft_printf("room: {lcyan}%s{def}\n", elem->room->name);
		ft_printf("arrived: {lgreen}%d{def}\n", elem->arrived);
		elem = elem->next;
	}
}
