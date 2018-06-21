/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:01:09 by lucien            #+#    #+#             */
/*   Updated: 2018/06/20 18:08:16 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		search_next_room(t_map *m, char *s1, char *s2)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strstr(s1, s2);
	while (new[i] && new[i] != '\n')
	{
		if (new[i] == '-')
			break ;
		m->soluc[m->i] = new[i];
		m->i++;
		i++;
	}
	m->soluc[m->i] = '-';
	m->i++;
}

static void	reset_target(t_map *m)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (m->soluc[i] != '-')
		i++;
	i += 1;
	while (m->start_tmp[j] && m->soluc[i + j])
	{
		if (m->soluc[i + j] == '\0')
			break ;
		m->start_tmp[j] = m->soluc[i + j];
		j++;
	}
	m->start_tmp[j] = '\0';
}

static void	init_process(t_map *m, int check)
{
	int		i;

	i = 0;
	while (m->start[i])
	{
		m->soluc[m->i] = m->start[i];
		i++;
		m->i++;
	}
	m->soluc[m->i] = '-';
	m->i++;
	if (m->soluc != NULL && check == 1)
	{
		i = 0;
		while (m->start[i])
		{
			m->start_tmp[i] = m->start[i];
			i++;
		}
		while (!(ft_strstr(m->links, m->start_tmp)))
			reset_target(m);
		check = 0;
	}
}

void		process(t_map *m)
{
	int		i;

	i = 0;
	while (m->start[i])
	{
		m->start_tmp[i] = m->start[i];
		i++;
	}
	i = 0;
	while (ft_strlen(m->links) != 0)
	{
		init_process(m, i);
		while (ft_strcmp(m->start_tmp, m->end) != 0)
		{
			search_next_room(m, m->links, m->start_tmp);
			delete_link(m, m->links, m->start_tmp);
			printf("soluc \n%s\n", m->soluc);
			printf("m->links \n%s\n", m->links);
			printf("m->start %s\n", m->start);
			printf("m->start_tmp %s\n", m->start_tmp);
		}
		i = 1;
		m->soluc[--m->i] = '\n';
		m->i++;
	}
}
