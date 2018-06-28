/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 00:15:22 by lucien            #+#    #+#             */
/*   Updated: 2018/06/28 16:35:39 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_istrstr(char *big, char *little)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strcmp(little, "") == 0)
		return (0);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j] || little[j] == '\0')
		{
			if (little[j] == '\0' && big[i + j] == '-' &&
			(ft_strlen(little) == ft_strlen_char(&big[i], '-')))
				return (i);
			else if (little[j] == '\0' && big[i - 1] == '-' &&
			(ft_strlen(little) == ft_strlen_char(&big[i], '\n')))
			{
				while (big[i] && big[i] != '\n')
					i--;
				return (i + 1);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

char	*ft_strstr_char(char *big, char *little)
{
	int		i;
	int		j;

	i = -1;
	if (ft_strcmp(little, "") == 0)
		return ((char*)big);
	while (big[++i])
	{
		j = 0;
		while (big[i + j] == little[j] || little[j] == '\0')
		{
			if (little[j] == '\0' && big[i + j] == '-' &&
			(ft_strlen(little) == ft_strlen_char(&big[i], '-')))
				return ((char*)&big[i + j + 1]);
			else if (little[j] == '\0' && big[i - 1] == '-' &&
			(ft_strlen(little) == ft_strlen_char(&big[i], '\n')))
			{
				while (big[i] && big[i] != '\n')
					i--;
				return ((char *)&big[i + 1]);
			}
			j++;
		}
	}
	return (NULL);
}
