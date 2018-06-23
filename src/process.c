/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:01:09 by lucien            #+#    #+#             */
/*   Updated: 2018/06/23 15:08:54 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_process(t_map *m)
{
	int		i;

	i = 0;
	m->len = ft_strlen(m->links) + 1;
	m->next_room = ft_strnew(m->len);
	m->soluc = ft_strnew(1000000);
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

static void	search_next_room(t_map *m)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(m->len);//initialise new
	check_loop(m);
	new = ft_strcpy(new, ft_strstr_char(m->links, m->next_room));
	while (new[i] && new[i] != '\n')//on vire la merde et on a que la soluc
	{
		if (new[i] == '-')
			break ;
		m->soluc[m->i] = new[i];
		m->i++;
		i++;
	}
	m->soluc[m->i] = '-';
	m->i++;
	m->soluc[m->i] = '\0';
	ft_strdel(&new);
}

void		process(t_map *m)
{
	init_process(m);
	while (ft_strlen(m->links) != 0)
	{
		while (ft_strcmp(m->next_room, m->end) != 0)
		{
			if (!(ft_strstr_char(m->links, m->next_room)))
			{
				if (save_best_path(m) == -1)
					return ;
			}
			search_next_room(m);
			delete_link(m, m->next_room);
			printf("\n---------------------------------\n\n");
			printf("solution en cours \n%s\n", m->soluc);
			printf("\nm->links \n%s\n", m->links);
			printf("\n---------------------------------\n\n");
		}
		m->soluc[--m->i] = '\n';
		save_last_soluc(m, m->soluc, ft_strlen(m->soluc));
		m->i++;
		if (ft_strlen(m->links) == 0)
			break ;
		else
			next_solution(m);
	}
}
