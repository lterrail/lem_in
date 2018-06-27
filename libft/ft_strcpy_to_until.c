/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_to_until.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:35:30 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/27 17:37:55 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_to_until(char *dest, char *src, char c, char d)
{
	int 	i;
	int		j;

	i = 0;
	j = 0;
	if (c == 'L')
		(void)c;
	else
	{
		while (src[i] != c)
			i++;
		i += 1;
	}
	while (src[i])
	{
		if (src[i] == d)
			break ;
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
