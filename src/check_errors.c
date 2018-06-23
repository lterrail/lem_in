/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:21:18 by lucien            #+#    #+#             */
/*   Updated: 2018/06/23 12:06:28 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_start_end(t_map *m)
{
	if (!(ft_strstr_char(m->links, m->end)))
		exit_func(m, NO_END_ROOM);

	if (!(ft_strstr_char(m->links, m->start)))
		exit_func(m, NO_START_ROOM);
}

void		check_double(t_map *m, char *s2)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strnew(BUFF_SIZE);
	tmp2 = ft_strnew(BUFF_SIZE);
	tmp = ft_strcpy_char(tmp, s2, 'L', '-');
	tmp2 = ft_strcpy_char(tmp2, s2, '-', '\n');
	if (ft_strcmp(tmp, tmp2) == 0)
		exit_func(m, DOUBLE_ERROR);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}
