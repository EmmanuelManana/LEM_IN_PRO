/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:14:48 by emanana           #+#    #+#             */
/*   Updated: 2019/09/19 17:55:54 by emanana          ###   ########.fr       */
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

int				fetch_key(char *key, int capacity)
{
	int		result;
	int		i;


	result = 0;
	i = -1;
	while (key[++i])
	{
		result = result + key[i];
	}
	result = result + ft_strlen(key);
	return (result % capacity);
}

void			graph_insert(t_graph *graph, t_room *room)
{
	t_node		*node;
	t_node		*temp;

	if (!(node = (t_node*)ft_memalloc(sizeof(t_node) * 1)))
		return ;
	node->key = fetch_key(room->name, graph->capacity);
	node->room = room;
	node->next = NULL;

	if (!graph->vn[node->key])/*if no vertex/room has this key*/
		graph->vn[node->key] = node;/*then this room/vertex takes this hey*/
	else 
	{
		temp = graph->vn[node->key];
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
	graph->size++;
}

t_room		*graph_find(t_graph *graph, char *name)
{
	t_node	*node;
	int		key;

	key = fetch_key(name, graph->capacity);
	if (!(node = graph->vn[key]))
		return (NULL);
	if (!ft_strcmp(node->room->name, name))
		return (node->room);
	while ((node = node->next))
		if (!ft_strcmp(node->room->name, name))
			return (node->room);
	return (NULL);
}

