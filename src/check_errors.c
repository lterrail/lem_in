/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:21:18 by lucien            #+#    #+#             */
/*   Updated: 2018/06/28 16:12:24 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_start_end(t_map *m)
{
	if (ft_istrstr(m->links, m->end) < 0)
		exit_func(m, NO_END_ROOM);
	if (ft_istrstr(m->links, m->start) < 0)
		exit_func(m, NO_START_ROOM);
}

void		check_double(t_map *m, char *s2)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strnew(BUFF_SIZE);
	tmp2 = ft_strnew(BUFF_SIZE);
	tmp = ft_strcpy_char(tmp, s2, '-');
	tmp2 = ft_strcpy_to_until(tmp2, s2, '-', '\n');
	if (ft_strcmp(tmp, tmp2) == 0)
		exit_func(m, DOUBLE_ERROR);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}
