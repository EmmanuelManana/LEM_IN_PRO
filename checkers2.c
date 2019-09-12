/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:17:27 by emanana           #+#    #+#             */
/*   Updated: 2019/09/12 17:49:51 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*confirm  the graph*/
void			check_graph(t_graph *graph)
{
	if (!graph->size)
		exit_error("Error: No rooms or invalid file");
	if (!graph->start)
		exit_error("Error: start room not found");
	if (!graph->end)
		exit_error("End room not found");
}

/*check for ants*/
int 			check_if_ants(char *line)
{
	int 		ants;

	if (!check_num(line))
	   exit_error("ERROR: Ants must be number");
	ants = ft_atoi(line);
	if (ants <= 0)
		exit_error("ERROR: number of ants must be  > 0 or  positive");
	if (ants > CAPACITY)
		exit_error("ERROR: Ants overload");
	return (ants);
}

/*check for a room*/
void			check_room(t_graph *graph, char *line,  int is_start, int  is_end)
{
	t_file_room	ret;
	int			x;
	int			y;
	char 		*name;
	char 		**info;

	info = ft_strsplit(line, ' ');
	if (!info || !info[0] || !info[1] || !info[2])
		exit_error("Unable to process room");
	if (!check_num(info[1]) || !check_num(info[2]))
	   exit_error("x OR y is not a number");
	name = ft_strdup(info[0]);
	x = ft_atoi(info[1]);
	y = ft_atoi(info[2]);
	if (!name || !*name || !check_room_name(name))
		exit_error("invalid room name");
	if (x < 0)
		exit_error("x must be a positive number");
	if (y < 0)
		exit_error("y must be a positive number");
	ret = (t_file_room){name, x, y, is_start, is_end};
	add_room(graph, ret);/*add room*/
	free_str(info);
}

/*check start and end rooms*/
void			check_start_and_end(t_graph *graph, char **line)
{
	int			s_or_e;;
	
	if ((s_or_e = !ft_strcmp(*line, "##start")) || !ft_strcmp(*line, "##end"))
	{
		free(*line);
		if (get_next_line(STDIN_FILENO, line) > 0)
			s_or_e ? check_room(graph, *line, 1, 0) : check_room(graph, *line, 0, 1);
		else 
			exit_error("Error processing ##start or ##end command from file"); 
	}
}
/*check links*/
void			check_link(t_graph *graph, char *line)
{
	t_file_link ret;
	char 		**links;

	links = ft_strsplit(line, '-');
	if (!links || !links[0] || !links[1])
		exit_error("invalid links/ could not process links");
	if (!check_room_name(links[0]) || !check_room_name(links[1]))
		exit_error("Invalid rooms name/s in link");
	ret = (t_file_link){links[0], links[1]};
	/*add_neighbor(graph, ret);add neighbor*/
	free_str(links);
}
