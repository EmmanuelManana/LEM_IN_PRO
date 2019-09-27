/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:42:31 by emanana           #+#    #+#             */
/*   Updated: 2019/09/16 11:40:58 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	check_num(char *num)
{
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}

int 	check_room_name(char *str)
{
	return (*str != '#' && *str != 'L');
}

void	final_checks(t_graph *graph, int  num)
{
	if (num == -1)/*gnl error */
		exit_error("error reading file");
	check_graph(graph);
}
