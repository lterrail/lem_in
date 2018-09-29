/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:29:36 by lterrail          #+#    #+#             */
/*   Updated: 2018/09/26 16:34:30 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <limits.h>

# define E_EMPTY_MAP			-2
# define E_ERROR 				-1
# define E_SUCCESS 				1
# define BAD_INSTRUCTION 		3
# define START_INSTRUCTION 		4
# define END_INSTRUCTION 		5
# define INSTRUCTION 			6
# define COMMENTARY 			7
# define LINK 					8
# define ROOM 					9
# define ANTS_ERROR 			10
# define PARSE_ROOM_ERROR 		11
# define PARSE_LINKS_ERROR 		12
# define NB_LINK_ERROR 			13
# define GET_LINKS_ERROR 		14
# define PARSE_ALL_ERROR 		15
# define ANTS 					16
# define DOUBLE_INSTRUCTION 	17
# define DUPLICATED_NAME 		18
# define NAME_ROOM_ERROR 		19
# define EMPTY_LINE				20

typedef struct			s_ant
{
	int					id;
	struct s_room		*room;
	struct s_room		*to;
	int					arrived;
	struct s_ant		*next;
}						t_ant;

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	struct s_room		**branch;
	int					link;
	int					distance;
	int					i_branch;
	int					occuped;
	struct s_room		*next;
}						t_room;

typedef struct			s_map
{
	t_room				*rooms;
	t_room				*start;
	t_room				*end;
	t_ant				*ants;
	char				*std;
	int					is_map;
	int					link;
	int					ant_in;
	int					ant_out;
	int					ant_per_turn;
	int					max_ant_per_turn;
	int					instruction;
}						t_map;

/*
**Error
*/

extern int				ft_error(t_map *m, int error);

/*
**Parsing
*/

int						init_parsing(t_map *m, int token, int error);
extern int				parse_nbr(t_map *m, char **line);
extern int				parse_instruction(t_map *m, char *line);
extern int				parse_commentary(t_map *m, char *line);
extern int				parse_all_room(t_map *m, char *line);
t_room					*parse_room(t_map *m, char *line, int *erno, int error);
extern int				parse_links(t_map *m, char *line);

/*
**Listing
*/

extern int				find_distance(t_room *room, int distance, char *start,
						char *end);

/*
**Print_ants
*/

extern void				print_ant(t_map *m, int ants, int ant_per_turn,
						int tot_ants);
extern void				init_print_ants(t_map *m);

/*
** Utils
*/

void					free_ants(t_ant *ant);
extern void				free_all(t_map *m);

#endif
