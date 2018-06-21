/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 00:15:22 by lucien            #+#    #+#             */
/*   Updated: 2018/06/20 17:26:41 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_int_strstr(const char *big, const char *little)
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
			if (little[j] == '\0' && big[i + j] == '-')
				return (i);
			else if (little[j] == '\0' && big[i - 1] == '-')
			{
				while (big[i] && big[i] != '\n')
					i--;
				return (i + 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_strlen_char(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char		*ft_strdup_char(const char *str, char c)
{
	int		i_str;
	int		j;
	char	*cpy;

	i_str = 0;
	j = 0;
	while (str[i_str] != c)
		i_str++;
	if (!(cpy = malloc(sizeof(char) * i_str + 1)))
		return (0);
	while (str[j] != c)
	{
		cpy[j] = str[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}

char		*str_join(char *s1, char *s2)
{
	char	*new;

	if (s1 == NULL)
		return (s2);
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcat(new, s1);
	ft_strcat(new, "\n");
	ft_strcat(new, s2);
	ft_strdel(&s1);
	return (new);
}
