/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TheColony2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:11:48 by emanana           #+#    #+#             */
/*   Updated: 2019/09/20 09:58:12 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		start_ants(t_ants *ants, int num)
{
	int		i;

	i = 0;
	while (++i <= num)
		add_ants(ants, num);
}
/*push and poping of ants*/
int			move_ants(t_room *from, t_room *to)
{
	int		num;

	num = remove_ants(from->ants);/*pop from */
	add_ants(to->ants, num);/*push to*/
	return (num);
}
