/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:29:36 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/27 19:12:48 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

#define BUFF_SIZE 32
#define ANTS_ERROR 10
#define READ_MAP_ERROR 11
#define LINKS_ERROR 12
#define SEARCH_ERROR 13
#define NO_END_ROOM 14
#define NO_START_ROOM 15
#define DOUBLE_ERROR 16
#define NO_SOLUC_ERROR 17

typedef struct		s_map
{
	int				ants;
	int				i;
	int				len;
	int				loop;
	char			*start;
	char			*next_room;
	char			*end;
	char			*soluc;
	char			*last_soluc;
	int				count;
	char			*links;
}					t_map;

/*
**read_map
*/

int					read_map(t_map *m);
void				count_ants(t_map *m, char *line);
void				links(t_map *m, char *line);
char				*str_join(t_map *m, char *s1, char *s2);

/*
**find_the_best_paths
*/

int					no_path(t_map *m, int ret, int nb);
void				process_find_paths(t_map *m);
void				check_loop(t_map *m);
void				backtracking(t_map *m);
void				next_solution(t_map *m);
void				delete_link(t_map *m, char *room);

/*
**print
*/

int					remove_useless_path(t_map *m, char **soluc, int nb_max);
void				process_ants(t_map *m);
void				print_ants(t_map *m, char **soluc, int nb);

/*
**check_error
*/

void				exit_func(t_map *m, int error);
void				check_start_end(t_map *m);
void				check_double(t_map *m, char *s2);

/*
**utils
*/

void				add_room_in_soluc(t_map *m, char *soluc, char *s2);
void				add_end_soluc(t_map *m, char *n_soluc, char *room);

char				*cpy_room(char *s1, char *s2);
char				*cpy_soluc(t_map *m, int nb);
char				*cpy_last_soluc_room(t_map *m, char *dst, char *src, char c);

void				remove_soluc(t_map *m, char *n_soluc, char *room);
int					remove_last_room(t_map *m);
void				remove_last_solution(t_map *m);

int					ft_int_strstr(char *big, char *little);
char				*ft_strstr_char(char *big, char *little);

void				print_data(t_map *m);


#endif
