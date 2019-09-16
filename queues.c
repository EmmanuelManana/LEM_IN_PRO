/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queues.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:53:02 by emanana           #+#    #+#             */
/*   Updated: 2019/09/16 16:41:39 by emanana          ###   ########.fr       */
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

t_room		*dequeue(t_queue *queue)
{
	t_node	*temp;
	t_room 	*room;

	if (!queue->front)
		return (NULL);
	temp = queue->front;
	queue->front = temp->next;
	if (!queue->front)
		queue->back = NULL;
	room = temp->room;
	free(temp);
	queue->size--;
	return (room);
}

void		free_queue(t_queue *queue)
{
	t_node	*temp;
	t_node	*node;

	if ((node = queue->front))
	{
		while (node)
		{
			temp = node;
			node = node->next;
			free(temp);
		}
	}
	free(queue);
}

int		isempty_queue(t_queue *queue)
{
	return (!queue->front);
}
