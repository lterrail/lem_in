/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:15:56 by lucien            #+#    #+#             */
/*   Updated: 2018/06/20 17:52:53 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_new_target(t_map *m, char *s1, char *s2)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strstr(s1, s2);
	while (tmp[i] && tmp[i] != '\n')
	{
		if (tmp[i] == '-')
			break ;
		m->start_tmp[i] = tmp[i];
		i++;
	}
	m->start_tmp[i] = '\0';
}

void		delete_link(t_map *m, char *s1, char *s2)
{
	int		i_clear;
	int		i_next;

	i_clear = ft_int_strstr(s1, s2);
	set_new_target(m, s1, s2);
	i_next = i_clear;
	while (s1[i_next] && s1[i_next] != '\n')
		i_next++;
	if (s1[i_next] == '\0')
	{
		m->links[i_clear] = '\0';
		return ;
	}
	i_next += 1;
	while (s1[i_next])
	{
		m->links[i_clear] = s1[i_next];
		i_clear++;
		i_next++;
	}
	m->links[i_clear] = '\0';
}
