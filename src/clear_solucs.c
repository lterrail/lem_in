/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_solucs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:04:34 by lucien            #+#    #+#             */
/*   Updated: 2018/06/25 17:25:59 by lucien           ###   ########.fr       */
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
	ft_strcpy_char(room, &soluc[m->i], 'L', '-');
	m->i += ft_strlen(room) + 1;
	return (room);
}

static int		remove_useless_path(t_map *m, char **soluc, int nb_max)
{
	int		j;
	int		i;
	char	*room;
	char	*tmp;
	int		supr;

	supr = nb_max;
	room = ft_strnew(m->len);
	tmp = ft_strnew(m->len);
	j = 0;
	m->i = ft_strlen(m->start) + 1;
	room = ft_strcpy(room, m->start);
	while (nb_max >= 2 && j + 1 < nb_max)
	{
		i = j + 1;
		while (nb_max >= 2 && i < nb_max)
		{
			while (read_room(m, room, soluc[j]) != NULL)
			{
				if (ft_int_strstr(soluc[i], room) && ft_strlen(soluc[j]) >= ft_strlen(soluc[i]))
				{
					printf("ici\n");
					ft_strcpy(tmp, soluc[j]);
					ft_strcpy(soluc[j], soluc[nb_max - 1]);
					ft_strcpy(soluc[nb_max - 1], tmp);
					supr--;
					break ;
				}
				else if (ft_int_strstr(soluc[i], room) && ft_strlen(soluc[j]) < ft_strlen(soluc[i]))
				{
					printf("la\n");
					ft_strcpy(tmp, soluc[i]);
					ft_strcpy(soluc[i], soluc[nb_max - 1]);
					ft_strcpy(soluc[nb_max - 1], tmp);
					supr--;
					break ;
				}
			}
			if (supr == nb_max)
			{
				i++;
			}
			else
				nb_max = supr;
		}
		j++;
	}
	ft_strdel(&room);
	ft_strdel(&tmp);
	return (nb_max);
}


static char		**sort_solution(char **soluc, int nb)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb - 1)
		{
			if (ft_strlen(soluc[j]) > ft_strlen(soluc[j + 1]))
			{
				tmp = soluc[j];
				soluc[j] = soluc[j + 1];
				soluc[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (soluc);
}

void			process_ants(t_map *m)
{
	int		nb_max;
	char	**soluc;
	int		ret;
	int		test;
	int		i;

	test = 0;
	i = 0;
	ret = 0;
	nb_max = count_char(m->soluc, '\n');
	printf("nb_max %d\n", nb_max);
	soluc = ft_strsplit(m->soluc, '\n');
	if (nb_max > 1)
	{
		ret = remove_useless_path(m, soluc, nb_max);
		soluc = sort_solution(soluc, ret);
		print_ants(m, soluc, ret);
		while (ret != nb_max)
		{
			ft_strdel(&soluc[ret]);
			ret++;
		}
	}
	else
		print_ants(m, soluc, 1);
	while (test != nb_max)
	{
		printf("\nsoluc[%d]%s\n", test, soluc[test]);
		test++;
	}
	while (soluc[i])
	{
		ft_strdel(&soluc[i]);
		i++;
	}
	free(soluc);
}
