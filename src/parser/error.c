/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:46:38 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/26 12:29:58 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

extern int	ft_error(t_map *m, int error)
{
	if (error == ANTS_ERROR)
		ft_putstr_fd("\e[91mError: \e[38;5;208mNumber of Ants\e[39m\n", 2);
	else if (error == PARSE_ROOM_ERROR)
		ft_putstr_fd("\e[91mError: \e[38;5;208mRoom Coordinate\e[39m\n", 2);
	else if (error == NB_LINK_ERROR)
		ft_putstr_fd("\e[91mError: \e[38;5;208mNumber of Links\e[39m\n", 2);
	else if (error == GET_LINKS_ERROR)
		ft_putstr_fd("\e[91mError: \e[38;5;208mUnlogical Link\e[39m\n", 2);
	else if (error == PARSE_ALL_ERROR)
		ft_putstr_fd("\e[91mError: \e[38;5;208mParsing Room\e[39m\n", 2);
	else if (error == DOUBLE_INSTRUCTION)
		ft_putstr_fd("\e[91mError: \e[38;5;208mDouble instructions\e[39m\n", 2);
	else if (error == DUPLICATED_NAME)
		ft_putstr_fd("\e[91mError: \e[38;5;208mDuplicated Room Name\e[39m\n"
			, 2);
	else if (error == NAME_ROOM_ERROR)
		ft_putstr_fd("\e[91mError: \e[38;5;208mRoom Name\e[39m\n", 2);
	else if (error == E_SUCCESS)
		ft_putstr_fd("\e[91mError: \e[38;5;208mLinks or Ants\e[39m\n", 2);
	else
		ft_putstr_fd("\e[91mError: \e[38;5;208mOthers\e[39m\n", 2);
	free_all(m);
	exit(0);
	return (0);
}
