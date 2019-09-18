/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheColony2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:11:48 by emanana           #+#    #+#             */
/*   Updated: 2019/09/18 12:21:49 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		start_ants(t_ants *ants, int num)
{
	int		i;

	i = 0;
	while (++i <= num)
		add_ants(to->ants, num);
	return (num);
}

int			move_ants(t_room *from, t_room *to)
{
	int		num;

	num = remove_ants(to->ants, num);
	add_ants(to->ants, num);
	return (num);
}
