/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:57:32 by lucien            #+#    #+#             */
/*   Updated: 2018/06/28 16:15:48 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		backtracking(t_map *m)
{
	int		i;

	i = remove_last_room(m);
	if (m->loop == 1)
		delete_link(m, &m->soluc[i]);
	m->loop = 0;
	m->soluc[m->i] = '\0';
	cpy_last_soluc_room(m, m->next_room, m->soluc, '-');
	m->next_room[ft_strlen(m->next_room)] = '\0';
	if ((ft_count_char(cpy_soluc(m, -1), '-') <= 1) && !(ft_strstr_char(m->links, m->next_room)))
	{
		remove_last_solution(m);
		print_data(m);
		//process_ants(m);
		exit_func(m, 0);
	}
	else if (!(ft_strstr_char(m->links, m->next_room)))
	{
		backtracking(m);
		m->loop++;
	}
}

void		check_loop(t_map *m)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strstr_char(m->links, m->next_room);
	m->room = ft_strcpy_char(m->room, tmp, '-');
	while (m->room[i] && m->room[i] != '\n')
	{
		if (m->room[i] == '-')
			break ;
		i++;
	}
	m->room[i] = '\0';
	if (ft_count_char(cpy_soluc(m, -1), '-') >= 1 &&
		ft_strstr_char(cpy_soluc(m, -1), m->room))
	{
		m->loop++;
		backtracking(m);
		m->loop = 0;
	}
}
