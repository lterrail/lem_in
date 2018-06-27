/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:26:15 by lucien            #+#    #+#             */
/*   Updated: 2018/06/27 19:13:45 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	zero_soluc(t_map *m, char *n_soluc, char *room, int nb_max)
{
	if (nb_max == 0 && ft_strlen(m->links) == 0)
	{
		ft_strdel(&n_soluc);
		ft_strdel(&room);
		exit_func(m, NO_SOLUC_ERROR);
	}
	else if (nb_max == 0)
	{
		backtracking(m);
		m->loop = 0;
		ft_strdel(&n_soluc);
		ft_strdel(&room);
		return (0);
	}
	return (0);
}

static int	worse_path(t_map *m, char *n_soluc, char *room)
{
	ft_strdel(&n_soluc);
	ft_strdel(&room);
	if (ft_strlen(m->links) == 0)
	{
		remove_last_solution(m);
		return (-1);
	}
	backtracking(m);
	return (0);
}

static int	better_path(t_map *m, char *n_soluc, char *room)
{
	add_end_soluc(m, n_soluc, room);
	remove_soluc(m, n_soluc, room);
	ft_strdel(&n_soluc);
	ft_strdel(&room);
	if (ft_strlen(m->links) == 0)
		return (-1);
	return (0);
}

static int	rollback_and_free(t_map *m, char *n_soluc, char *room)
{
	backtracking(m);
	m->loop = 0;
	ft_strdel(&n_soluc);
	ft_strdel(&room);
	if (ft_strlen(m->links) == 0)
		return (-1);
	return (0);
}

int			no_path(t_map *m, int ret, int nb)
{
	char	*room;
	char	*n_soluc;
	int		nb_max;

	room = ft_strnew(m->len);
	room = cpy_last_soluc_room(m, room, m->soluc, '-');
	n_soluc = cpy_soluc(m, nb);
	nb_max = ft_count_char(m->soluc, '\n');
	ret = zero_soluc(m, n_soluc, room, nb_max);
	while (nb != nb_max)
	{
		n_soluc = cpy_soluc(m, nb);
		if (ft_int_strstr(n_soluc, room) && (ft_int_strstr(n_soluc, room) <=
		ft_int_strstr(cpy_soluc(m, -1), room)))
			ret = worse_path(m, n_soluc, room);
		else if (ft_int_strstr(n_soluc, room) && (ft_int_strstr(n_soluc, room) >
		ft_int_strstr(cpy_soluc(m, -1), room)))
			ret = better_path(m, n_soluc, room);
		else if (nb == nb_max - 1)
			ret = rollback_and_free(m, n_soluc, room);
		nb++;
	}
	return (ret);
}
