/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:58:47 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/26 16:34:58 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_token(char *line)
{
	int		i;

	i = 0;
	if (line[0] == '\0')
		return (EMPTY_LINE);
	if (line[0] == '#' && line[1] == '#')
		return (INSTRUCTION);
	if (line[0] == '#')
		return (COMMENTARY);
	while (line[i] && !ft_strhas_char(line, ' '))
	{
		if (line[i] == '-')
			return (LINK);
		line++;
	}
	if (ft_str_is_number(line))
		return (ANTS);
	return (ROOM);
}

static int	parse_all(t_map *m, char *line, int token, int error)
{
	if (token == INSTRUCTION)
	{
		if (parse_instruction(m, line) == BAD_INSTRUCTION)
			return (DOUBLE_INSTRUCTION);
	}
	else if (token == COMMENTARY)
		parse_commentary(m, line);
	else if (token == ROOM && !m->link)
	{
		if ((error = parse_all_room(m, line)) != E_SUCCESS)
			return (error);
	}
	else if (token == LINK && m->start && m->end)
	{
		if (parse_links(m, line) == GET_LINKS_ERROR)
			return (GET_LINKS_ERROR);
	}
	else if (token == ANTS && m->ant_in == 0)
	{
		if (parse_nbr(m, &line) == ANTS_ERROR)
			return (ANTS_ERROR);
	}
	else
		return (PARSE_ALL_ERROR);
	return (E_SUCCESS);
}

static int	get_stdin(t_map *m, char *line, int link)
{
	char *get_line;

	if (!(get_line = ft_strjoin(m->std, line)))
		return (E_ERROR);
	free(line);
	free(m->std);
	if (!(m->std = ft_strjoin(get_line, "\n")))
		return (E_ERROR);
	free(get_line);
	if (m->start && m->end && m->ant_in && link)
		m->is_map = 1;
	return (E_SUCCESS);
}

int			init_parsing(t_map *m, int token, int e)
{
	char	*line;

	if (!(m->std = ft_strnew(0)))
		return (E_ERROR);
	while (get_next_line(0, &line) > 0)
	{
		token = get_token(line);
		m->link = (token == LINK) ? m->link + 1 : m->link;
		if (m->ant_in == 0 && token != 7 && token != 16)
		{
			free(line);
			return (ANTS_ERROR);
		}
		if ((e = parse_all(m, line, token, e)) >= 10)
		{
			free(line);
			break ;
		}
		if (!(get_stdin(m, line, m->link)))
			return (E_ERROR);
	}
	if (!m->is_map && (e >= 11 || !m->link || !m->start->link || !m->end->link))
		ft_error(m, e);
	return (E_SUCCESS);
}
