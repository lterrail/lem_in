/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:36:32 by lucien            #+#    #+#             */
/*   Updated: 2018/08/07 16:46:04 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, int n)
{
	char	*ptr;

	ptr = NULL;
	if (str != NULL)
	{
		ptr = ft_strnew(n + 1);
		if (ptr == NULL)
			return (NULL);
		ft_strncpy(ptr, str, n);
		ptr[n] = '\0';
	}
	return (ptr);
}
