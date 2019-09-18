/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:28:41 by emanana           #+#    #+#             */
/*   Updated: 2019/09/18 16:59:04 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_move(int num, char *dst, int i)
{
	if (i)
		ft_putstr(" ");
	ft_putchar('L');
	ft_putnbr(num);
	ft_putchar('-');
	ft_putstr(dst);
}

void		print_entry(t_room *room)
{
	/*if room is start
	 * 				print ##start*;
	 else if room is end
	 				print ##end
	
	*otherwise print (room->name room->x and room->y, its positions);*/
	if (room->is_start)
		ft_putstr("##start\n");
	if (room->is_end)
		ft_putstr("##end\n");
	ft_putstr(room->name);
	ft_putnbr(room->point.x);
	ft_putnbr(room->point.y);
	ft_putchar(10);
}

void		print_neighbors(t_graph *visited, t_node *n)
{

}

void		print_rooms(t_graph *graph)
{
	/*access each node and print  the graph
	 * aslong as the capacity is not eexceeded
	 * print every room/vertexe
	** */
	int i;
	t_node *nroom;

	i = -1;
	while (++i < graph->capacity)
	{
		nroom  = graph->vn[i];
		while(nroom)
		{
			print_entry(nroom->room);
			nroom = nroom->next;
		}
	}
}

void		print_links(t_graph *graph)
{

}
