/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:52:42 by lucien            #+#    #+#             */
/*   Updated: 2018/06/24 00:01:18 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	cpy_soluc_tmp(t_map *m, char *tmp) //copie le last_solution dans solution jusqu'à là où 'lon veut'
{
	int		i;
	int		n;

	i = 0;
	n = ft_int_strstr(m->last_soluc, tmp) + ft_strlen(tmp);
	if (n - ft_strlen(tmp) == 0)
		add_room_in_soluc(m, m->soluc, m->start);
	else
	{
		while (i <= n)
		{
			m->soluc[m->i] = m->last_soluc[i];
			m->i++;
			i++;
		}
	}
}

static void	read_soluc(t_map *m, char *s2, int i)
{
	i -= 2;
	while (i > 0 && s2[i] != '\n')
		i--;
	if (i != 0)
		i += 1;
	ft_strcpy_char(m->last_soluc, &s2[i], 'L', '\n');
}

static char	*get_next_room(t_map *m, char *tmp) //change la room pour la suivante
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	i = ft_int_strstr(m->last_soluc, tmp) + ft_strlen(tmp) + 1;
	while (m->last_soluc[i] != '-')
	{
		if (m->last_soluc[i] == '\0') //si on a parcouru tout last_solu sans trouver de lien entre target et soluc alors tu vas à la soluc d'avant
		{
			i = ft_strlen(m->soluc) - ft_strlen(m->last_soluc) - 1;
			read_soluc(m, m->soluc, i);
			i = 0;
			j = 0;
		}
		tmp[j] = m->last_soluc[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

void		next_solution(t_map *m)
{
	char	*tmp;
	int		check;

	check = 0;
	tmp = ft_strnew(m->len);
	tmp = ft_strcpy(tmp, m->start);
	if (!(ft_strstr(m->links, m->start)) && (ft_strlen(m->last_soluc) -
	(ft_strlen(m->start) + ft_strlen(m->end) + 1) == 0))
	{
		print_data(m);
		exit_func(m, 0);
	}
	while (check != 1)
	{
		if (ft_strstr_char(m->links, tmp))
		{
			cpy_soluc_tmp(m, tmp);
			ft_strcpy(m->next_room, tmp);
			check = 1;
		}
		else
			tmp = get_next_room(m, tmp);
	}
	ft_strdel(&tmp);
}
