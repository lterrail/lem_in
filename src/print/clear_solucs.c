/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_solucs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:04:34 by lucien            #+#    #+#             */
/*   Updated: 2018/06/28 12:29:44 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	len(t_map *m, char *soluc)
{
	int		i;

	i = m->i;
	while (soluc[i])
	{
		if (soluc[i] == '-')
			return (0);
		i++;
	}
	return (i);
}

static char		*read_room(t_map *m, char *room, char *soluc)
{
	if (soluc[m->i + len(m, soluc)] == '\0')
	{
		m->i = ft_strlen(m->start) + 1;
		room = ft_strcpy(room, m->start);
		return (NULL);
	}
	ft_strcpy_char(room, &soluc[m->i], '-');
	m->i += ft_strlen(room) + 1;
	return (room);
}

int		remove_useless_path(t_map *m, char **soluc, int len_tab)
{
	int		j;
	int		i;
	char	*room;
	char	*tmp;
	int		supr;

	supr = len_tab;
	room = ft_strnew(m->len);
	tmp = ft_strnew(m->len);
	j = 0;
	m->i = ft_strlen(m->start) + 1;
	room = ft_strcpy(room, m->start);
	while (len_tab >= 2 && j + 1 < len_tab)
	{
		i = j + 1;
		while (len_tab >= 2 && i < len_tab)
		{
			while (read_room(m, room, soluc[j]) != NULL)
			{
				if (ft_istrstr(soluc[i], room) && ft_strlen(soluc[j]) >= ft_strlen(soluc[i]))
				{
					ft_strcpy(tmp, soluc[j]);
					ft_strcpy(soluc[j], soluc[len_tab - 1]);
					ft_strcpy(soluc[len_tab - 1], tmp);
					supr--;
					break ;
				}
				else if (ft_istrstr(soluc[i], room) && ft_strlen(soluc[j]) < ft_strlen(soluc[i]))
				{
					ft_strcpy(tmp, soluc[i]);
					ft_strcpy(soluc[i], soluc[len_tab - 1]);
					ft_strcpy(soluc[len_tab - 1], tmp);
					supr--;
					break ;
				}
			}
			if (supr == len_tab)
			{
				i++;
			}
			else
				len_tab = supr;
		}
		j++;
	}
	ft_strdel(&room);
	ft_strdel(&tmp);
	return (len_tab);
}
