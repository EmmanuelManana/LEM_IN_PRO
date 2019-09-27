/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:06:59 by emanana           #+#    #+#             */
/*   Updated: 2019/09/04 15:41:08 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		exit_error(char *str)
{
	ft_putendl("ERROR: ");
	ft_putstr(str);
	exit(1);
}

void	 	free_str(char **str)
{
	int 	i;

	i  = -1;
	while (str[++i])
	{
		free(str[i]);
	}
	free(str);
}
