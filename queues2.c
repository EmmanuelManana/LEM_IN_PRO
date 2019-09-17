#include "lem_in.h"

t_room		*next_queue(t_queue *queue)
{
	t_node	*node;
	int	i;

	if ((node = queue->front))
	{
		i = -1;
		while (++i < queue->index)
		{
			node = node->next;
		}
		queue->index++;
	}
	return (node ? node->room : NULL);
}

t_room		*next_queue_unvisited(t_queue *queue)
{
	t_room *room;

	room = NULL;
	if (queue->front)
		while ((room = next_queue(queue)) && room->visited)
			;
	return (room);
}

void		reset_queue(t_queue *queue)
{
	queue->index = 0;
}

int		delete_queue(t_queue **queue, t_room *room)
{
	t_node	*node;
	t_node	*prev;

	if ((node = (*queue)->front))
	{
		prev = NULL;
		while (node)
		{
			if (node->room = room)
			{
				if (prev)
					prev->next = node->next;
				else 
					(*queue)->front = node->next;
				node == (*queue)->back ? (*queue)->back = prev : NOP();
				(*queue)->index ? (*queue)->index-- : NOP();			
				(*queue)->size--;
				free(node);
				return (1);
			}
			prev = node;
			node = node->next;
		}
	}
	return (0);
}
