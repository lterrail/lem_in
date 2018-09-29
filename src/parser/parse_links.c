/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:38:29 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/26 16:35:04 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		recursive_find_links(t_room *a, t_room *b, int flag)
{
	t_room	**new;
	int		i;

	i = 0;
	if (!(new = malloc(sizeof(t_room *) * (a->link + 1))))
		return (E_ERROR);
	while (i < a->link)
	{
		new[i] = a->branch[i];
		i++;
	}
	if (a->link)
		free(a->branch);
	a->branch = new;
	new[i] = b;
	a->link++;
	if (!flag)
		return (recursive_find_links(b, a, 1));
	return (E_SUCCESS);
}

extern int		parse_links(t_map *m, char *line)
{
	t_room	*a;
	t_room	*b;
	size_t	i;

	i = 0;
	a = m->rooms;
	if (line[i] == '-')
		return (GET_LINKS_ERROR);
	while (line[i] && line[i] != '-')
		i++;
	while (a && (i != ft_strlen(a->name) || ft_strncmp(a->name, line, i)))
		a = a->next;
	if (!a || ft_strncmp(a->name, line, i))
		return (GET_LINKS_ERROR);
	b = m->rooms;
	while (b && ft_strcmp(b->name, line + i + 1))
		b = b->next;
	if (!b || !ft_strcmp(a->name, b->name))
		return (GET_LINKS_ERROR);
	recursive_find_links(a, b, 0);
	return (E_SUCCESS);
}
