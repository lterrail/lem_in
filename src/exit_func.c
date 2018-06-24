/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 22:32:18 by lucien            #+#    #+#             */
/*   Updated: 2018/06/24 21:52:21 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		exit_func(t_map *m, int error)
{
	printf("error          = %d\n", error);
	ft_strdel(&m->start);
	ft_strdel(&m->end);
	ft_strdel(&m->links);
	ft_strdel(&m->soluc);
	ft_strdel(&m->next_room);
	ft_strdel(&m->last_soluc);
	free(m);
	if (error)
		ft_putstr_fd("ERROR\n", 2);
	exit(error);
}
