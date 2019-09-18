

#include "lem_in.h"

int		isempty_ants(t_ants *ants)
{
	return (!ants->front);
}

int			remove_ants(t_ants *ants)
{
	t_ants *ant;
	int	num;

	if (!ants->front)
		return (0);
	ant = ants->front;
	ants->front = ant->next;
	if (!ants->front)
		ants->back = NULL;
	num = ant->num;
	free(ant);
	ants->size--;
	return (num);
}

void			free_ants(t_ants *ants)
{
	t_ant		*ant;
	t_ant		*temp;

	if ((ant = ants->front))
	{
		while (ant)
		{
			temp = ant;
			ant = ant->next;
			free(ant);
		}
	}
	free(ants);
}
