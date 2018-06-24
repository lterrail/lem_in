/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:29:36 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/24 12:12:54 by lucien           ###   ########.fr       */
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

typedef struct		s_data
{
	char			*line;
	char			*tmp;
	int				index;
	struct s_data	*next;
}					t_data;

int					save_best_path(t_map *m, int ret, int nb);

/*
**read_map
*/

int					read_map(t_map *m);
void				count_ants(t_map *m, char *line);
void				links(t_map *m, char *line);
char				*str_join(t_map *m, char *s1, char *s2);

/*
**process
*/

void				process(t_map *m);

/*
**process - if_loop
*/
void				check_loop(t_map *m);
void				rollback_soluc(t_map *m);

/*
**process - next_solution
*/

void				next_solution(t_map *m);

/*
**process - delete links
*/

void				delete_link(t_map *m, char *room);

/*
**sort_and_print_ants
*/

void				sort_solution(t_map *m);

/*
**libft modified
*/

int					ft_int_strstr(char *big, char *little);
char				*ft_strdup_char(const char *str, char c);
size_t				ft_strlen_char(char *str, char c);
char				*ft_strcpy_char(char *dest, char *src, char c, char d);
char				*ft_strcat_char(t_map *m, char *dest, char *src, char c);
char				*ft_strstr_char(char *big, char *little);

/*
**utils lem_in
*/

char				*cpy_one_room(char *s1, char *s2);
void				add_room_in_soluc(t_map *m, char *soluc, char *s2);
char				*cpy_last_soluc_room(t_map *m, char *dst, char *src, char c);
int					remove_last_room(t_map *m);
void				remove_last_solution(t_map *m);

/*
**utils lem_in2
*/

int					count_char(char *str, char c);
char				*save_soluc(t_map *m, int nb);
void				delete_soluc(t_map *m, char *n_soluc, char *room);
void				add_end_soluc(t_map *m, char *n_soluc, char *room);

/*
**utils
*/

void				exit_func(t_map *m, int error);
int					get_next_line(const int fd, char **line);
void				print_data(t_map *m);

/*
**check_errors
*/

void				check_start_end(t_map *m);
void				check_double(t_map *m, char *s2);

#endif
