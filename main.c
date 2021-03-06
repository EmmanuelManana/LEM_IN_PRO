/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:22:44 by emanana           #+#    #+#             */
/*   Updated: 2019/09/18 16:09:29 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	t_graph  	*graph;
	int			vn;

	graph = init_graph(5000);
	/*validate and load data*/
	vn = load_data(graph);
	print_rooms(graph);
	return (0);
}
