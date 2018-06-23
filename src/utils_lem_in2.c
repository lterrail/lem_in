/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lem_in2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:02:58 by lucien            #+#    #+#             */
/*   Updated: 2018/06/23 21:46:39 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_char(char *str, char c)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

char		*save_soluc(t_map *m, int nb)
{
	int		i;
	char	*tmp;

	tmp = ft_strnew(m->len);
	if (nb == -1)
		return (cpy_last_soluc_room(m, tmp, m->soluc, '\n'));
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

void		add_end_soluc(t_map *m, char *n_soluc, char *room)
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

void		delete_soluc(t_map *m, char *n_soluc, char *room)
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
