/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:24:51 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/09/14 12:48:42 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printnum_arr(int *arr, size_t nb_val)
{
	int i;

	i = 0;
	while (i < (int)nb_val)
	{
		ft_putnbr((int)arr[i]);
		if (i != (int)nb_val - 1)
			ft_putstr(" - ");
		i++;
	}
}
