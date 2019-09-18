/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:08:43 by emanana           #+#    #+#             */
/*   Updated: 2019/09/18 16:10:36 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			load_data(t_graph *graph)
{
	int 	validater;
	int 	gnlfd;
	char 	*line;

	line  = NULL;
	validater = -1;
	while ((gnlfd = get_next_line(STDIN_FILENO, &line) > 0))
	{
		/* if [(line > ## ) > 0 && cmp(##line, 2) == 0*] is true*/
		if (!ft_strncmp(line, "##", 2))
			check_start_and_end(graph, &line);
		else if (*line == '#')
			NOP();/* no operation, operation*/
		else if (validater == -1)
			validater = check_if_ants(line);
		else if (check_room_name(line) && ft_strchr(line,' '))
			check_room(graph,  line, 0, 0);
		else if (check_room_name(line) && ft_strchr(line,'-'))
			check_link(graph, line);
		else 
			exit_error("Empty-line OR invalid line"); 
		free(line);
	}
	final_checks(graph, gnlfd);/*check if get next line read correctly*/
	line = NULL;/* not leavin a dangling pointer */
	return (validater);
}

/*build, name and populate, initialize the room*/
t_room		*init_room(t_file_room file_room)
{
	t_room	*room;

	if (!(room = (t_room*)ft_memalloc(sizeof(t_room) *  1)))
		return (NULL);
	/*filing the room*/
	room->name = file_room.name;
	room->point.x = file_room.x;
	room->point.y = file_room.y;
	room->is_start = file_room.is_start;
	room->is_end = file_room.is_end;

	room->vn = 0;
	room->visited = 0;
	room->neighbors = init_queue();
//	room->ants = init_ants();
	return (room); /* return a valid room*/
}

void		add_room(t_graph *graph, t_file_room filed_room)
{
	t_room	*this_room;

	this_room = init_room(filed_room);
	graph_insert(graph, this_room);
	if (filed_room.is_start)
	{
		if (graph->start)
			exit_error("No-more than 1 start is allowed");
		graph->start = this_room;
	}
	if (filed_room.is_end)
	{
		if (graph->end)
			exit_error("No-more than 1 end is allowed");
		graph->end =this_room;
	}
}

