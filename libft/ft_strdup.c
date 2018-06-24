/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:29:42 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/24 22:09:43 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i_str;
	int		j;
	char	*cpy;

	i_str = 0;
	j = 0;
	while (str[i_str])
		i_str++;
	if (!(cpy = malloc(sizeof(char) * i_str + 1)))
		return (0);
	while (str[j])
	{
		cpy[j] = str[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}
