/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:33:17 by lterrail          #+#    #+#             */
/*   Updated: 2018/08/07 16:37:02 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lem_in_init(t_map *m, char *line)
{
	free(line);
	m->ants_in = 0;
	m->ants_out = 0;
	m->instruction = 0;
	m->rooms = NULL;
	m->links = NULL;
	m->start = NULL;
	m->end = NULL;
}

static int		get_token(char *line)
{
	int		i;

	i = 0;
	if (line[0] == '#' && line[1] == '#')
		return (INSTRUCTION);
	if (line[0] == '#')
		return (COMMENTARY);
	while (line[i])
	{
		if (line[i] == '-')
			return (LINK);
		line++;
	}
	return (ROOM);
}

int				main(void)
{
	t_map	m;
	char	*line;
	int		token;

	if (get_next_line(0, &line) <= 0 || parse_nbr(&m, &line) == ANTS_ERROR)
		return (ANTS_ERROR);
	lem_in_init(&m, line);
	while (get_next_line(0, &line) > 0)
	{
		token = get_token(line);
		if (token == INSTRUCTION)
			parse_intruction(&m, line);
		else if (token == COMMENTARY)
			parse_commentary(&m, line);
		else if (parse_room(&m, line) == PARSE_ROOM_ERROR &&
				parse_links(&m, line, 0) == PARSE_LINKS_ERROR)
			break ;
		free(line);
	}
	printf("test\n");
	return (0);
}
