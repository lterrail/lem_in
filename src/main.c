/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:33:17 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/20 17:03:59 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_map	*map_init(void)
{
	t_map	*m;

	m = NULL;
	if (!(m = malloc(sizeof(t_map))))
		return  (NULL);
	m->ants = 0;
	m->i = 0;
	m->count = 0;
	m->soluc = ft_strnew(1000);
	m->links = NULL;
	m->start = NULL;
	m->start_tmp = ft_strnew(1000);
	m->end = NULL;
	return (m);
}

void			print_data(t_map *m)
{
	printf("soluc = \n%s\n", m->soluc);
	printf("ants = %d\n", m->ants);
	printf("start = %s\n", m->start);
	printf("tmp start = %s\n", m->start_tmp);
	printf("end = %s\n", m->end);
	printf("count = %d\n", m->count);
}

int				main(void)
{
	t_map	*m;

	m = map_init();
	if (read_map(m) != 4)
		exit_func(m, READ_MAP_ERROR);
	process(m);
	print_data(m);
	exit_func(m, 0);
	return (0);
}