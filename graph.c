/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:14:48 by emanana           #+#    #+#             */
/*   Updated: 2019/09/04 17:06:07 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_graph			*init_graph(int capacity)
{
	t_graph		*graph;
	int			i;

	graph = ft_memalloc(sizeof(t_graph) * 1);
	if (!(graph->vn = (t_node**)ft_memalloc(sizeof(t_node*) * capacity)))
		return (NULL);
	i = 0;
	while (i  < capacity)
		graph->vn[i++] = NULL;
	graph->capacity = capacity;
	graph->size = 0;
	graph->start = NULL;
	graph->end = NULL;
	return (graph);
}
