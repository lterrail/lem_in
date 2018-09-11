/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:17:26 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/28 19:23:27 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		last_line(char **line, char *str)
{
	if (!(*line = ft_strdup(str)))
		return (-1);
	ft_memset(str, '\0', ft_strlen(str));
	return (1);
}

static char		*read_line(int fd, char *str, int *ret)
{
	char	buff[BUFF_SIZE + 1];
	char	*new;

	ft_bzero(buff, BUFF_SIZE);
	*ret = read(fd, buff, BUFF_SIZE);
	buff[*ret] = '\0';
	if (!(new = ft_strjoin(str, buff)))
		return (NULL);
	ft_strdel(&str);
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*str = "";
	char		*tmp;

	ret = 1;
	tmp = NULL;
	if (!line || fd < 0 || (str[0] == '\0' && (!(str = ft_strnew(BUFF_SIZE)))))
		return (-1);
	while (ret > 0)
	{
		if ((tmp = ft_strchr(str, '\n')) != NULL)
		{
			*tmp = '\0';
			if (!((*line) = ft_strdup(str)))
				return (-1);
			ft_memcpy(str, tmp + 1, ft_strlen(tmp + 1) + 1);
			return (1);
		}
		if (!(str = read_line(fd, str, &ret)))
			return (-1);
	}
	ft_strdel(&tmp);
	if (ret == 0 && str && ft_strlen(str))
		return (last_line(&(*line), str));
	return (ret);
}
