/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:46:25 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/27 17:46:53 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_room_in_soluc(t_map *m, char *soluc, char *s2)
{
	int		i;

	i = 0;
	while (s2[i] && s2[i] != '\n')
	{
		if (s2[i] == '-')
			break ;
		soluc[m->i] = s2[i];
		m->i++;
		i++;
	}
	soluc[m->i] = '-';
	m->i++;
	soluc[m->i] = '\0';
}

void		add_end_soluc(t_map *m, char *n_soluc, char *room)
{
	int		i;

	i = ft_int_strstr(n_soluc, room);
	while (n_soluc[i] != '-')
		i++;
	i++;
	m->i += ft_strlen_char(&n_soluc[i], '\n');
	ft_strcat_char(m->soluc, &n_soluc[i], '\n');
	m->i += ft_strlen_char(&n_soluc[i], '\n');
	m->soluc[m->i] = '\n';
	m->i++;
	m->soluc[m->i] = '\0';
}
