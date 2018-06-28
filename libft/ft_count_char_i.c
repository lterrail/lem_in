/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:17:13 by lucien            #+#    #+#             */
/*   Updated: 2018/06/28 15:29:42 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_char_i(char *str, char c, int len)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i] && i <= len)
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}
