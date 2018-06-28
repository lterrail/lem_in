/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:26:15 by lucien            #+#    #+#             */
/*   Updated: 2018/06/28 17:57:38 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	zero_soluc(t_map *m, char *n_soluc, int len_tab)
{
	if (len_tab == 0 && ft_strlen(m->links) == 0)
	{
		ft_strdel(&n_soluc);
		exit_func(m, NO_SOLUC_ERROR);
	}
	else if (len_tab == 0)
	{
		backtracking(m);
		ft_strdel(&n_soluc);
		m->loop = 0;
		return (0);
	}
	return (0);
}

static int	worse_path(t_map *m, char *n_soluc)
{
	ft_strdel(&n_soluc);
	if (ft_strlen(m->links) == 0)
	{
		remove_last_solution(m);
		return (-1);
	}
	backtracking(m);
	return (0);
}

static int	better_path(t_map *m, char *n_soluc)
{
	add_end_soluc(m, n_soluc, m->room);
	remove_soluc(m, n_soluc, m->room);
	ft_strdel(&n_soluc);
	if (ft_strlen(m->links) == 0)
		return (-1);
	return (0);
}

static int	rollback_and_free(t_map *m, char *n_soluc)
{
	backtracking(m);
	m->loop = 0;
	ft_strdel(&n_soluc);
	if (ft_strlen(m->links) == 0)
		return (-1);
	return (0);
}

int			no_path(t_map *m, int ret, int nb)
{
	char	*n_soluc;
	int		len_tab;

	m->room = cpy_last_soluc_room(m, m->room, m->soluc, '-');
	n_soluc = cpy_soluc(m, nb);
	len_tab = ft_count_char(m->soluc, '\n');
	ret = zero_soluc(m, n_soluc, len_tab);
	while (nb != len_tab)
	{
		ft_strdel(&n_soluc);
		n_soluc = cpy_soluc(m, nb);
		if (ft_istrstr(n_soluc, m->room) && (ft_istrstr(n_soluc, m->room) <=
		ft_istrstr(cpy_soluc(m, -1), m->room)))
			ret = worse_path(m, n_soluc);
		else if (ft_istrstr(n_soluc, m->room) && (ft_istrstr(n_soluc, m->room) >
		ft_istrstr(cpy_soluc(m, -1), m->room)))
			ret = better_path(m, n_soluc);
		else if (nb == len_tab - 1)
			ret = rollback_and_free(m, n_soluc);
		nb++;
	}
	return (ret);
}
