/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:29:36 by lterrail          #+#    #+#             */
/*   Updated: 2018/08/07 16:30:12 by lucien           ###   ########.fr       */
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

#define E_ERROR -1
#define E_SUCCESS 1
#define NO_INSTRUCTION 3
#define START_INSTRUCTION 4
#define END_INSTRUCTION 5
#define INSTRUCTION 6
#define COMMENTARY 7
#define LINK 8
#define ROOM 9
#define ANTS_ERROR 10
#define PARSE_ROOM_ERROR 11
#define PARSE_LINKS_ERROR 12

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_room
{
	struct s_room	*next;
	struct s_room	**branch;
	int				distance;
	int				linked;
	int				x;
	int				y;
	char			*name;
	int				occuped;
}					t_room;

typedef struct		s_map
{
	t_room			*rooms;
	int				ants_in;
	int				ants_out;
	int				instruction;
	t_room			*start;
	t_room			*end;
	char			*links;
}					t_map;

int					parse_nbr(t_map *m, char **line);
int					parse_intruction(t_map *m, char *line);
int					parse_commentary(t_map *m, char *line);
int					parse_room(t_map *m, char *line);
int					parse_links(t_map *m, char *line, int i);

int					room_link(t_room *one, t_room *two, int flag);
int					room_add(t_map *m, char *name, t_coord *c);

#endif
