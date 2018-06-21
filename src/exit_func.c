/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 22:32:18 by lucien            #+#    #+#             */
/*   Updated: 2018/06/20 15:41:10 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		exit_func(t_map *m, int error)
{
	printf("error = %d\n", error);
	free(m->start);
	free(m->end);
	free(m->links);
	free(m->soluc);
	free(m->start_tmp);
	free(m);
	if (error)
		ft_putstr_fd("ERROR\n", 2);
	exit(error);
}
