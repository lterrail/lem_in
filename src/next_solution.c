/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:52:42 by lucien            #+#    #+#             */
/*   Updated: 2018/06/23 12:52:12 by lucien           ###   ########.fr       */
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
	{
		while (m->start[i])
		{
			m->soluc[m->i] = m->start[i];
			m->i++;
			i++;
		}
		m->soluc[m->i++] = '-';
		m->soluc[m->i + 1] = '\0';
	}
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
			save_last_soluc(m, m->soluc, i);
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

void		next_solution(t_map *m) //fonction qui cherche par où l'on va commencer la prochaine solution
{
	char	*tmp;
	int		check;

	check = 0;
	tmp = ft_strnew(m->len);
	tmp = ft_strcpy(tmp, m->start); //tmp correspond a la valeur qu'on cherche apres avoir changer de solution
	while (check != 1)
	{
		if (ft_strstr_char(m->links, tmp)) //si start est dans link alors tu commences direct
		{
			cpy_soluc_tmp(m, tmp);  //si c'est le cas tu copies la soluc -1 n dans soluc
			ft_strcpy(m->next_room, tmp); //next target
			check = 1;
		}
		else
			tmp = get_next_room(m, tmp); //c'est ici que tu avances dans soluc -1
	}
	ft_strdel(&tmp);
}

void		save_last_soluc(t_map *m, char *s2, int i)
{
	int		j;

	j = 0;
	i -= 2;
	while (i > 0 && s2[i] != '\n') //je recule jusqu'à arriver au début de la précedente solution
	{
		i--;
	}
	if (i != 0)
		i += 1;
	while (s2[i] != '\n')
	{
		m->last_soluc[j] = s2[i]; //je copie la derniere solution
		j++;
		i++;
	}
	m->last_soluc[j] = '\0';  //je fais propre
	printf("toto\n");
	printf("m->last_soluc %s\n", m->last_soluc);
}
