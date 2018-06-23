/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:57:32 by lucien            #+#    #+#             */
/*   Updated: 2018/06/23 23:12:49 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		rollback_soluc(t_map *m) //je réécris ma solution en enlevant le doublon
{
	int		i;

	printf("loop\n");
	printf("m->soluc %s\n", m->soluc);
	i = remove_last_room(m);
	if (m->loop == 1)
		printf("\n &m->soluc[i] %s\n", &m->soluc[i]);
	if (m->loop == 1)
		delete_link(m, &m->soluc[i]);
	m->loop = 0;
	m->soluc[m->i] = '\0';
	cpy_last_soluc_room(m, m->next_room, m->soluc, '-');
	m->next_room[ft_strlen(m->next_room)] = '\0';
	if ((count_char(save_soluc(m, -1), '-') <= 1) && !(ft_strstr_char(m->links, m->next_room)))
	{
		remove_last_solution(m);
		print_data(m);
		exit_func(m, 0);
	}
	else if (!(ft_strstr_char(m->links, m->next_room)))
	{
		rollback_soluc(m);
		m->loop++;
	}
}

void		check_loop(t_map *m) //cherche si deux valeurs sont identiques dans soluc
{
	char	*new;
	char	*tmp;
	int		i;

	i = 0;
	new = ft_strnew(m->len);
	tmp = ft_strstr_char(m->links, m->next_room);
	new = ft_strcpy(new, tmp);
	while (new[i] && new[i] != '\n')
	{
		if (new[i] == '-')
			break ;
		i++;
	}
	new[i] = '\0';
	if (count_char(save_soluc(m, -1), '-') >= 1 && ft_strstr_char(save_soluc(m, -1), new)) //si tu trouves une double valeur dans soluc actuelle, rollback
	{
		m->loop++;
		rollback_soluc(m);
		m->loop = 0;
	}
	ft_strdel(&new);
}
