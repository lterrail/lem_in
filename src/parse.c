/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 14:19:42 by lucien            #+#    #+#             */
/*   Updated: 2018/08/07 16:50:23 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			parse_room(t_map *m, char *line)
{
	char	*name;
	t_coord	coord;
	int		i;

	i = 0;
	if (line && *line == 'L')
		return (PARSE_ROOM_ERROR);
	while (line[i] && line [i] != ' ')
		i++;
	if (!i || line[i] != ' ' || !(name = ft_strndup(line, i++)))
		return (PARSE_ROOM_ERROR);
	coord.x = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i++] != ' '|| coord.x < 0 || (coord.y = ft_atoi(line + i)) < 0)
		return (PARSE_ROOM_ERROR);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] != '\0')
		return (PARSE_ROOM_ERROR);
	return (room_add(m, name, &coord));
}

int			parse_links(t_map *m, char *line, int i)
{
	t_room	*one;
	t_room	*two;

	one = m->rooms;
	while (line[i] && line[i] != '-')
		i++;
	while (one && (ft_strncmp(one->name, line, (int)ft_strlen(one->name)) ||
			i != (int)ft_strlen(one->name)))
		one = one->next;
	if (!one || !line[i])
		return (line[i] ? parse_links(m, line, i + i) : PARSE_LINKS_ERROR);
	two = m->rooms;
	while (two && ft_strcmp(two->name, line + i + 1))
		two = two->next;
	if (!two || one == two)
		return (line[i] ? parse_links(m, line, i + 1) : PARSE_LINKS_ERROR);
	i = -1;
	while (++i < one->linked)
		if (one->branch[i] == two)
			return (PARSE_LINKS_ERROR);
	return (room_link(one, two, 0));
}

int			parse_nbr(t_map *m, char **line)
{
	int		ants;

	ants = 0;
	if ((ants = ft_atoi(*line)) > 0)
		m->ants_in = ants;
	else
		return (ANTS_ERROR);
	printf("ants %d\n", m->ants_in);
	return (E_SUCCESS);
}

int			parse_intruction(t_map *m, char *line)
{
	if (!ft_strcmp(line, "##start"))
		return (m->instruction = START_INSTRUCTION);
	else if (!ft_strcmp(line, "##end"))
	 	return (m->instruction = END_INSTRUCTION);
	else
		return (m->instruction = NO_INSTRUCTION);
}

int			parse_commentary(t_map *m, char *line)
{
	m += 1;
	line += 1;
	return (E_SUCCESS);
}
