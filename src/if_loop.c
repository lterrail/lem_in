/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:57:32 by lucien            #+#    #+#             */
/*   Updated: 2018/06/23 15:10:49 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	rollback_next_room(t_map *m)
{
	int		i;

	i = m->i - 2;
	printf("m->i %d\n, i %d\n", m->i, i);
	while (i > 0 && m->soluc[i] != '-')
	{
		if (m->soluc[i] == '\n')
			break ;
		i--;
	}
	if (i != 0)
		i += 1;
	ft_strcpy_char(m->next_room, &m->soluc[i], 'L', '-');
	m->next_room[ft_strlen(m->next_room)] = '\0';
	if (!(ft_strstr_char(m->links, m->next_room)))
	{
		rollback_soluc(m);
		m->loop++;
	}
}

void		rollback_soluc(t_map *m) //je réécris ma solution en enlevant le doublon
{
	int		i;
	char	*tmp;

	printf("loop\n");
	tmp = ft_strnew(m->len);
	m->i -= 2; //je saute le '-'
	while (m->soluc[m->i] != '-') //je saute la chaine de caractere
		m->i--;
	m->i++; //je reviens sur le premier caractere
	i = m->i;
	tmp = ft_strcpy_char(tmp, &m->soluc[i], 'L', '-');
	if (m->loop == 1)
		delete_link(m, tmp);
	m->loop = 0;
	m->soluc[m->i] = '\0'; //pour l'écracer par un backslash zero, je laisse donc le '-'
	printf("m->soluc in loop %s\n", m->soluc);
	rollback_next_room(m);
	ft_strdel(&tmp);
}

char		*actual_soluc(t_map *m)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	tmp = ft_strnew(m->len);
	i = m->i - 1;
	while (i > 0 && m->soluc[i] != '\n')
		i--;
	if (i != 0)
		i += 1;
	while (m->soluc[i])
	{
		if (m->soluc[i] == '\n')
			break ;
		tmp[j] = m->soluc[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

void		remove_last_solution(t_map *m)
{
	m->i = m->i - 2; //pour arriver sur la dernière room de solution qui bug
	while (m->i > 0)
	{
		if (m->soluc[m->i] == '\n')
			break ;
		m->i--;
	}
	m->soluc[m->i] = '\0';
}

static int	count_char(char *str, char c)
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

void		check_loop(t_map *m)
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
	if (count_char(actual_soluc(m), '-') > 1 && ft_strstr_char(actual_soluc(m), new)) //si tu trouves une double valeur dans soluc actuelle, rollback
	{
		m->loop++;
		rollback_soluc(m);
		m->loop = 0;
	}
	ft_strdel(&new);
}
