/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_find_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:01:09 by lucien            #+#    #+#             */
/*   Updated: 2018/06/28 17:17:02 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_process(t_map *m)
{
	int		i;

	i = 0;
	m->len = ft_strlen(m->links);
	m->room = ft_strnew(BUFF_SIZE + 100);
	m->next_room = ft_strnew(m->len);
	m->soluc = ft_strnew(m->len);
	m->last_soluc = ft_strnew(m->len);
	while (m->start[i])
	{
		m->next_room[i] = m->start[i];
		m->soluc[m->i] = m->start[i];
		m->i++;
		i++;
	}
	m->soluc[m->i++] = '-';
}

static void	complete_soluc(t_map *m)
{
	check_loop(m);
	m->room = ft_strcpy_char(m->room,
		ft_strstr_char(m->links, m->next_room), '-');
	add_room_in_soluc(m, m->soluc, m->room);
}

void		process_find_paths(t_map *m)
{
	init_process(m);
	while (ft_strlen(m->links) != 0)
	{
		while (ft_strcmp(m->next_room, m->end) != 0)
		{
			if (!(ft_strstr_char(m->links, m->next_room)))
			{
				if (no_path(m, 0, 0) == -1)
				{
					m->soluc[m->i + 1] = '\0';
					m->soluc[m->i] = '\n';
					return ;
				}
			}
			complete_soluc(m);
			delete_link(m, m->next_room);
			/*printf("\n---------------------------------\n\n");
			printf("solution en cours \n%s\n", m->soluc);
			printf("\nm->links \n%s\n", m->links);*/
		}
		m->soluc[--m->i] = '\n';
		m->last_soluc = ft_strcpy(m->last_soluc, cpy_soluc(m, -1));
		m->i++;
		if (ft_strlen(m->links) == 0)
			break ;
		else
			next_solution(m);
	}
}
