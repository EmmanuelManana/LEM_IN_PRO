/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:11:43 by emanana           #+#    #+#             */
/*   Updated: 2019/09/11 16:19:50 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEM_IN_H_
# define _LEM_IN_H_
# include "libft/libft.h"

/*lacate ants*/
typedef struct 		s_position
{
	int				x;
	int				y;
}					t_point;

/*
 * define an ant
 */
typedef struct 			s_ant
{
	struct s_ant		*next;
	int					no;
}                       t_ant;

/*
 * define a number of ants
 */
typedef struct 			s_ants
{
	t_ant				*back;
	t_ant				*front;
	int					size;
}						t_ants;
/*
 * define a room
 */
typedef struct			s_room
{
	char	 			*name;
	t_point 	      	point; /*where in x and y */
	int					vn;
	int					visited;
	int					is_start;
	int					is_end;
	struct s_room	 	*prev;
	struct s_queue		*neighbors;
	struct a_ants		*ants;
} 						t_room;	

typedef struct 		s_node
{
	int				key;
	t_room			*room;
	struct s_node   *next;
}					t_node;

/*
 * define a graph
 */ 
typedef struct		s_graph
{
	t_node			**vn;
	t_room			*end;
	t_room			*start;
	int 			capacity;
	int				size;
} 					t_graph;

/*
 * queue ants
 */
typedef struct 		s_queue
{
	int				size;
	int				index;
	t_node          *front;
	t_node          *back;
}					t_queue;

typedef struct		file_room
{
	char 			*name;
	int				x;
	int				y;
	int				is_start;
	int				is_end;
}					t_file_room;

typedef struct 		file_link
{
	char			*a;
	char			*b;
}					t_file_link;


/*
 * build graph
 */
t_graph				*init_graph(int capacity);
int					fetch_key(char *key, int capacity);
/*
 * helper
 */
void				exit_error(char *str);
void				free_str(char **str);
/*
 * error handling and checks
 */
int 				check_num(char *num);/*no*/
int 				check_room_name(char *str);
void				check_graph(t_graph *graph);
void 				check_if_ants(char *line);
void				check_start_&_end(t_graph *graph,  char **line);
void				check_room(t_graph *graph, char *line, int is_start, int is_end);
void				final_checks(t_graph *graph, int num);
void				check_link(t_graph *graph, char *line);

					/*add_room*/
					/*add_neighbor*/
/*initialize*/
void				
		/*init_queue();*/
void				init_queue(void);
			/*init_ants*/
void				init_ants(void);

/*proccess rooms*/
int					load_data(t_graph *graph);
t_graph				*build_room(t_file_room f_room);
t_room				*init_room(t_file_room file_room);
void				add_room(t_graph *graph, t_file_room f_room);
#endif











