/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queues.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:53:02 by emanana           #+#    #+#             */
/*   Updated: 2019/09/16 14:28:05 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue		*init_queue(void)
{
	t_queue *q;

	if (!(q = (t_queue*)ft_memalloc(sizeof(t_queue) * 1)))
		return (NULL);
	q->size = 0;
	q->index = 0;
	q->front = NULL;
	q->back = NULL;
	return (q);
}


void			enqueue(t_queue *queue, t_room *room)
{
	t_node		*node;

	if (!(node = (t_node*)ft_memalloc(sizeof(t_node) * 1)))
		return ;
	node->room = room;
	node->next = NULL;
	node->key = 0;
	if (!queue->front)
	{
		 queue->front = node;
		 queue->back = node;
	}
	else
	{
		queue->back->next = node;
		queue->back = node;
	}
	queue->size++;
}
