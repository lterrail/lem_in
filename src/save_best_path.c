/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_best_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:26:15 by lucien            #+#    #+#             */
/*   Updated: 2018/06/23 15:07:30 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	*save_last_room(t_map *m)
{
	char	*last_room;
	int		i;

	i = 0;
	last_room = ft_strnew(m->len);
	i = m->i - 2;
	while (m->soluc[i] != '-')
		i--;
	i++;
	ft_strcpy_char(last_room, &m->soluc[i], 'L', '-');
	return (last_room);
}

static char	*read_soluc(t_map *m, int nb)
{
	int		i;
	char	*tmp;

	tmp = ft_strnew(m->len);
	i = 0;
	while (nb != 0)
	{
		while (m->soluc[i] != '\n')
			i++;
		i++;
		nb--;
	}
	return (ft_strcpy_char(tmp, &m->soluc[i], 'L', '\n'));
}

static void	add_end_soluc(t_map *m, char *n_soluc, char *room)
{
	int		i;

	i = ft_int_strstr(n_soluc, room);
	while (n_soluc[i] != '-')
		i++;
	i++;
	ft_strcat_char(m, m->soluc, &n_soluc[i], '\n');
	m->soluc[m->i] = '\n';
	m->i++;
	m->soluc[m->i] = '\0';
}

static void	delete_soluc(t_map *m, char *n_soluc, char *room)
{
	int		i_start;
	int		i_next;
	int		len;

	i_start = ft_int_strstr(n_soluc, room);
	while (i_start > 0 && m->soluc[i_start] != '\n')
		i_start--;
	if (i_start != 0)
		i_start += 1;
	i_next = i_start;
	while (m->soluc[i_next] != '\n')
		i_next++;
	i_next++;
	len = ft_strlen_char(m->soluc, '\n');
	ft_strcpy(&m->soluc[i_start], &m->soluc[i_next]);
	m->i -= len;
	next_solution(m);
}

int		save_best_path(t_map *m)
{
	char	*room;
	char	*n_soluc;
	int		nb;
	int		nb_max;
	int		i;

	i = 0;
	nb = 0;
	nb_max = 0;
	room = save_last_room(m);
	n_soluc = read_soluc(m, nb);
	while (m->soluc[i])
	{
		if (m->soluc[i] == '\n')
			nb_max++;
		i++;
	}
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
	while (nb != nb_max)
	{
		n_soluc = read_soluc(m, nb);
		if (ft_int_strstr(n_soluc, room) && (ft_int_strstr(n_soluc, room) <= ft_int_strstr(actual_soluc(m), room)))
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
		else if (ft_int_strstr(n_soluc, room) && (ft_int_strstr(n_soluc, room) > ft_int_strstr(actual_soluc(m), room)))
		{
			add_end_soluc(m, n_soluc, room);
			delete_soluc(m, n_soluc, room);
			ft_strdel(&n_soluc);
			ft_strdel(&room);
			if (ft_strlen(m->links) == 0)
				return (-1);
			return (0);
		}
		else if (nb == nb_max - 1)
		{
			rollback_soluc(m);
			m->loop = 0;
			ft_strdel(&n_soluc);
			ft_strdel(&room);
			if (ft_strlen(m->links) == 0)
				return (-1);
			return (0);
		}
		nb++;
	}
	return (0);
}
