/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 00:15:22 by lucien            #+#    #+#             */
/*   Updated: 2018/06/23 12:07:14 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_int_strstr(char *big, char *little)
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
	return (0);
}

size_t			ft_strlen_char(char *str, char c)
{
	size_t	i;

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

char	*ft_strcpy_char(char *dest, char *src, char c, char d)
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

char	*ft_strcat_char(t_map *m, char *dest, char *src, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		if (src[j] == c)
			break ;
		dest[i] = src[j];
		i++;
		j++;
		m->i++;
	}
	dest[i] = '\0';
	return (dest);
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
