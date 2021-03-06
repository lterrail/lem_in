/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhaszero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:22:48 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/02 08:26:53 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strhaszero(char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '.' && str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		if (str[i] > 48 && str[i] <= 57)
			return (0);
		i++;
	}
	return (0);
}
