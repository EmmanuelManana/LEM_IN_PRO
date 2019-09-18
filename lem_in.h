/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:11:43 by emanana           #+#    #+#             */
/*   Updated: 2019/09/16 16:41:09 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEM_IN_H_
# define _LEM_IN_H_
# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"

# define NOP() ({;})
# define CAPACITY 5000

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
	int					num;
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

typedef struct 		s_node/*room/ vertex*/
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
 * queue's
 */
typedef struct 		s_queue
{
	int				size;
	int				index;
	t_node          *front;/* *next*/
	t_node          *back;/* *next */
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

/*graph and map*/
t_graph				*init_graph(int capacity);
int				fetch_key(char *key, int capacity);
void				graph_insert(t_graph *graph, t_room *room);

void				exit_error(char *str);
void				free_str(char **str);

/*checks*/
int 				check_num(char *num);/*no*/
int 				check_room_name(char *str);
void				check_graph(t_graph *graph);
int 				check_if_ants(char *line);
void				check_start_and_end(t_graph *graph,  char **line);
void				check_room(t_graph *graph, char *line, int is_start, int is_end);
void				final_checks(t_graph *graph, int num);
void				check_link(t_graph *graph, char *line);
/*init*/
int				load_data(t_graph *graph);
void				add_room(t_graph *graph, t_file_room filed_room);
t_room				*init_room(t_file_room file_room);
/*---> add neighbor --->*/

/*enques*/
t_queue 			*init_queue(void);
void				enqueue(t_queue *queue, t_room *room);
t_room				*dequeue(t_queue *queue);
void				free_queue(t_queue *queue);
int				isempty_queue(t_queue *queue);
t_room				*next_queue(t_queue *queue);
t_room				*next_queue_unvisited(t_queue *queue);
void				reset_queue(t_queue *queue);
int				delete_queue(t_queue **queue, t_room *room);

/*let there be ants*/
void				add_ants(t_ants	*ants, int num);
int				remove_ants(t_ants *ants);
t_ants				*init_ants(void);
int				move_ants(t_room *from, t_room *to);
void				free_ants(t_ants *ants);
void				start_ants(t_ants *ants, int num);
int				isempty_ants(t_ants *ants, int num);


#endif











