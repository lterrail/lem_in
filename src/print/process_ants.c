/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:43:30 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/27 19:18:16 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			process_ants(t_map *m)
{
	int		len_tab;
	char	**soluc;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	len_tab = ft_count_char(m->soluc, '\n');
	soluc = ft_strsplit(m->soluc, '\n');
	if (len_tab > 1)
	{
		ret = remove_useless_path(m, soluc, len_tab);
		soluc = ft_buble_sort_tab(soluc, ret);
		print_ants(m, soluc, ret);
	}
	else
		print_ants(m, soluc, 1);
	while (soluc[i])
	{
		ft_strdel(&soluc[i]);
		i++;
	}
	free(soluc);
}
