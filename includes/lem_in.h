/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:29:36 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/20 17:23:53 by lucien           ###   ########.fr       */
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

typedef struct		s_map
{
	int				ants;
	int				i;
	char			*start;
	char			*start_tmp;
	char			*end;
	char			*soluc;
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

/*
**get_datas
*/

int					read_map(t_map *m);
void				count_ants(t_map *m, char *line);
void				links(t_map *m, char *line);

/*
**process
*/

void				search_next_room(t_map *m, char *s1, char *s2);
void				process(t_map *m);

/*
**utils
*/

int					ft_int_strstr(const char *big, const char *little);
char				*str_join(char *s1, char *s2);
char				*ft_strdup_char(const char *str, char c);
int					ft_strlen_char(char *str, char c);

void				exit_func(t_map *m, int error);
int					get_next_line(const int fd, char **line);

void				delete_link(t_map *m, char *s1, char *s2);
void				set_new_target(t_map *m, char *s1, char *s2);


#endif
