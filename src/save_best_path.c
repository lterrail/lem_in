/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_best_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:26:15 by lucien            #+#    #+#             */
/*   Updated: 2018/06/23 21:46:24 by lucien           ###   ########.fr       */
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
		rollback_soluc(m);
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
	rollback_soluc(m);
	return (0);
}

static int	better_path(t_map *m, char *n_soluc, char *room)
{
	add_end_soluc(m, n_soluc, room);
	delete_soluc(m, n_soluc, room);
	ft_strdel(&n_soluc);
	ft_strdel(&room);
	if (ft_strlen(m->links) == 0)
		return (-1);
	return (0);
}

static int	rollback_and_free(t_map *m, char *n_soluc, char *room)
{
	rollback_soluc(m);
	m->loop = 0;
	ft_strdel(&n_soluc);
	ft_strdel(&room);
	if (ft_strlen(m->links) == 0)
		return (-1);
	return (0);
}

int			save_best_path(t_map *m, int ret)
{
	char	*room;
	char	*n_soluc;
	int		nb;
	int		nb_max;

	nb = 0;
	room = ft_strnew(m->len);
	room = cpy_last_soluc_room(m, room, m->soluc, '-');
	n_soluc = save_soluc(m, nb);
	nb_max = count_char(m->soluc, '\n');
	ret = zero_soluc(m, n_soluc, room, nb_max);
	while (nb != nb_max)
	{
		n_soluc = save_soluc(m, nb);
		if (ft_int_strstr(n_soluc, room) && (ft_int_strstr(n_soluc, room) <= ft_int_strstr(save_soluc(m, -1), room)))
			ret = worse_path(m, n_soluc, room);
		else if (ft_int_strstr(n_soluc, room) && (ft_int_strstr(n_soluc, room) > ft_int_strstr(save_soluc(m, -1), room)))
			ret = better_path(m, n_soluc, room);
		else if (nb == nb_max - 1)
			ret = rollback_and_free(m, n_soluc, room);
		nb++;
	}
	return (ret);
}
