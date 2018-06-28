/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 22:06:26 by lucien            #+#    #+#             */
/*   Updated: 2018/06/28 17:58:02 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			read_map(t_map *m)
{
	char *line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (m->ants == 0)
		{
			count_ants(m, line);
			m->count++;
		}
		else if (ft_strcmp("##start", line) == 0 && m->start == NULL)
		{
			ft_strdel(&line);
			get_next_line(STDIN_FILENO, &line);
			m->start = ft_strdup_char(line, ' ');
			m->count++;
		}
		else if (ft_strcmp("##end", line) == 0 && m->end == NULL)
		{
			ft_strdel(&line);
			get_next_line(STDIN_FILENO, &line);
			m->end = ft_strdup_char(line, ' ');
			m->count++;
		}
		else if (ft_strchr(line, '-') && line[0] != '#')
			links(m, line);
		ft_strdel(&line);
	}
	return (m->count);
}

void		count_ants(t_map *m, char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (line[0] == '#')
		exit_func(m, ANTS_ERROR);
	s = ft_strtrim(line);
	while (s[i] && s[i] != '\n')
	{
		if (!ft_isdigit(s[i++]))
		{
			ft_strdel(&s);
			exit_func(m, ANTS_ERROR);
		}
	}
	if ((m->ants = ft_atoi(s)) <= 0)
	{
		ft_strdel(&s);
		exit_func(m, ANTS_ERROR);
	}
	ft_strdel(&s);
}

char		*str_join(t_map *m, char *s1, char *s2)
{
	char	*new;

	check_double(m, s2);
	if (s1 == NULL)
		return (s2);
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcat(new, s1);
	ft_strcat(new, "\n");
	ft_strcat(new, s2);
	ft_strdel(&s1);
	return (new);
}

void		links(t_map *m, char *line)
{
	if (m->links == NULL)
		m->count++;
	m->links = str_join(m, m->links, line);
}
