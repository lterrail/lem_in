/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:33:17 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/26 16:34:46 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_map	*lem_in_init(void)
{
	t_map *m;

	if (!(m = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	m->rooms = NULL;
	m->start = NULL;
	m->end = NULL;
	m->link = 0;
	m->is_map = 0;
	m->ant_in = 0;
	m->ant_out = 0;
	m->ant_per_turn = 0;
	m->max_ant_per_turn = 0;
	m->instruction = 0;
	return (m);
}

int				main(void)
{
	t_map	*m;

	m = lem_in_init();
	if (init_parsing(m, 0, NB_LINK_ERROR) == 1)
	{
		find_distance(m->end, 0, m->start->name, m->end->name);
		if (m->start->distance == -1)
			ft_putstr_fd("\e[91mError: \e[38;5;208mNo Solution\n\e[39m", 2);
		else
		{
			m->start->occuped = 1;
			ft_printf("%s\n", m->std);
			init_print_ants(m);
			free_ants(m->ants);
		}
		free_all(m);
	}
	else
	{
		ft_putstr_fd("\e[91mError: \e[38;5;208mInvalid Map or Ants\n\e[39m", 2);
		free_all(m);
	}
	return (0);
}
