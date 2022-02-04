/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:18:31 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 16:05:03 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

int	map_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	add_wall(t_global *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map.lines[i])
	{
		j = 0;
		while (g->map.lines[i][j])
		{
			if (g->map.lines[i][j] == ' ' || g->map.lines[i][j] == '\t')
				g->map.lines[i][j] = '1';
			j++;
		}
		i++;
	}
	return ;
}
