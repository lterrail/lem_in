/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_else.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:12:44 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/26 17:02:54 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

extern int	parse_nbr(t_map *m, char **line)
{
	int		ants;

	ants = 0;
	if (!ft_strhas_digit(*line))
		return (ANTS_ERROR);
	if ((ants = ft_atoi(*line)) > 0 && ants <= INT_MAX)
		m->ant_in = ants;
	else
		return (ANTS_ERROR);
	return (E_SUCCESS);
}

extern int	parse_instruction(t_map *m, char *line)
{
	if (!ft_strcmp(line, "##start") && !m->start)
		m->instruction = START_INSTRUCTION;
	else if (!ft_strcmp(line, "##end") && !m->end)
		m->instruction = END_INSTRUCTION;
	else if (ft_strcmp(line, "##start") && ft_strcmp(line, "##end"))
		return (E_SUCCESS);
	else
		return (m->instruction = BAD_INSTRUCTION);
	return (E_SUCCESS);
}

extern int	parse_commentary(t_map *m, char *line)
{
	m += 1;
	line += 1;
	return (E_SUCCESS);
}

static void	parse_create_lst_rooms(t_room **begin_room, t_room *new)
{
	t_room	*begin;

	begin = *begin_room;
	if (begin)
	{
		while (begin->next)
			begin = begin->next;
		begin->next = new;
		new->next = NULL;
	}
	else
	{
		*begin_room = new;
		new->next = NULL;
	}
}

extern int	parse_all_room(t_map *m, char *line)
{
	t_room	*curr_room;
	int		*erno;
	int		error;
	int		ret;

	error = 0;
	if (!(erno = (int *)malloc(sizeof(int))))
		return (E_ERROR);
	*erno = E_SUCCESS;
	if (!(curr_room = parse_room(m, line, erno, error)))
	{
		free(curr_room);
		ret = *erno;
		free(erno);
		return (ret);
	}
	parse_create_lst_rooms(&m->rooms, curr_room);
	free(erno);
	return (E_SUCCESS);
}
