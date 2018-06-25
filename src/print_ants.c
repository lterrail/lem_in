/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucien <lucien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:59:02 by lucien            #+#    #+#             */
/*   Updated: 2018/06/25 18:02:20 by lucien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		*init_tab_ants(int nb, char **soluc)
{
	int		*tab_ants;
	int		i;
	int		len;

	i = 0;
	len = count_char(soluc[i], '-');
	nb = len * nb;
	if (!(tab_ants = malloc(sizeof(int) * nb + 1)))
		return (NULL);
	while (nb > i)
	{
		tab_ants[i] = i + 1;
		i++;
	}
	i = 0;
	while (i < nb)
	{
		printf("tab_ants[test] %d\n", tab_ants[i]);
		i++;
	}
	return (tab_ants);
}

static char		*read_ants(char *room, char *soluc, int turn)
{
	int		len;
	int		i;
	int		rang;

	i = ft_strlen_char(soluc, '-') + 1; //commence a n + 1
	len = count_char(&soluc[i], '-') + 1; //compte le nombre de soluc n + 1
	rang = turn % len; //modulo le tour par le nb de soluc pour trouver à quel rang je suis
	while (rang != 0) //calcul le i du rnag où je suis puis le print
	{
		while (soluc[i] != '-')
			i++;
		i++;
		rang--;
	}
	room = ft_strcpy_char(room, &soluc[i], 'L', '-');
	return (room);
}

static int		idk(t_map *m, int *tab_ants, char *room, char **soluc, int turn, int nb, int j, int ants)
{
	printf("L%d-", tab_ants[j]);
	printf("%s ", read_ants(room, soluc[0 + 0], turn));
	if (ft_strstr(room, m->end))
	{
		tab_ants[j] += nb + 1;
		ants++;
	}
	return (ants);
}

void		print_ants(t_map *m, char **soluc, int nb)
{
	int		j;
	char	*room;
	int		turn;
	int		ants;
	int		*tab_ants;

	tab_ants = init_tab_ants(nb, soluc);
	ants = nb;
	printf("nb %d\n", nb);
	turn = 0;
	room = ft_strnew(m->len);
	j = 0;
	while (ants <= m->ants)
	{
		j = 0;
		while (j < nb)
		{
			ants = idk(m, tab_ants, room, soluc, turn - j, nb, j, ants);
			if (ft_strcmp(room, "1") != 0 && nb < 4)
				nb++;
			j++;
			printf("\n");
		}
		//printf("TU BRANLES QUOI \n");
		printf("\n");
		turn++;
	}
	ft_strdel(&room);
}






// static int		*init_tab_ants(int nb, char **soluc)
// {
// 	int		*tab_ants;
// 	int		i;
// 	int		len;
//
// 	i = 0;
// 	len = count_char(soluc[i], '-');
// 	nb = len * nb;
// 	if (!(tab_ants = malloc(sizeof(int) * nb + 1)))
// 		return (NULL);
// 	while (nb >= i)
// 	{
// 		tab_ants[i] = i + 1;
// 		i++;
// 	}
// 	i = 0;
// 	while (i <= nb)
// 	{
// 		printf("tab_ants[test] %d\n", tab_ants[i]);
// 		i++;
// 	}
// 	return (tab_ants);
// }
//
// static char		*read_ants(char *room, char *soluc, int turn)
// {
// 	int		len;
// 	int		i;
// 	int		rang;
//
// 	i = ft_strlen_char(soluc, '-') + 1; //commence a n + 1
// 	len = count_char(&soluc[i], '-') + 1; //compte le nombre de soluc n + 1
// 	rang = turn % len; //modulo le tour par le nb de soluc pour trouver à quel rang je suis
// 	while (rang != 0) //calcul le i du rnag où je suis puis le print
// 	{
// 		while (soluc[i] != '-')
// 			i++;
// 		i++;
// 		rang--;
// 	}
// 	room = ft_strcpy_char(room, &soluc[i], 'L', '-');
// 	return (room);
// }
//
// void			print_ants(t_map *m, char **soluc, int nb)
// {
// 	char	*room;
// 	int		ants;
// 	int		*tab_ants;
//
// 	tab_ants = init_tab_ants(nb);
// 	ants = 0;
// 	room = ft_strnew(m->len);
// 	while (ants <= m->ants)
// 	{
// 		while (j <= nb)
// 		{
// 			printf("L%d-", tab_ants[j]);
// 			printf("%s ", read_ants(room, soluc[j], turn));
// 		}
// 	}
// 	ft_strdel(&room);
// }
