/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheColony.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:40:30 by emanana           #+#    #+#             */
/*   Updated: 2019/09/20 09:44:29 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lem_in.h"

int		isempty_ants(t_ants *ants)
{
	return (!ants->front);
}

int			remove_ants(t_ants *ants)
{
	t_ant	*ant;
	int		num;

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

void		add_ants(t_ants *ants, int num)
{
	t_ant	*ant;

	ant = (t_ant*)ft_memalloc(sizeof(t_ant) * 1);
	ant->num = num;
	ant->next = NULL;
	if (!ants->front)
	{
		ants->front = ant;
		ants->back = ant;
	}
	else
	{
		ants->back->next = ant;
		ants->back = ant;
	}
	ants->size++;
}

t_ants		*init_ants(void)
{
	t_ants *ants;

	ants = (t_ants*)ft_memalloc(sizeof(t_ants) * 1);
	ants->front = NULL;
	ants->back = NULL;
	ants->size = 0;
	return (ants);
}
