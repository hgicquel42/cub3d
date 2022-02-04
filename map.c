/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:18:31 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 08:42:25 by vpiamias         ###   ########.fr       */
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
	while (g->xmap.map[i])
	{
		j = 0;
		while (g->xmap.map[i][j])
		{
			if (g->xmap.map[i][j] == ' ' || g->xmap.map[i][j] == '\t')
				g->xmap.map[i][j] = '1';
			j++;
		}
		i++;
	}
	return ;
}

int	get_map_info(t_global *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->xmap.map[i] != NULL)
	{
		j = 0;
		while (g->xmap.map[i][j] == ' ')
			j++;
		if (g->xmap.map[i][j] == 'N' && g->xmap.map[i][j + 1] == 'O' && g->xmap.map[i][j + 2] == ' ')
			g->xmap.header.north = ft_strdup(g->xmap.map[i] + j + 3);
		if (g->xmap.map[i][j] == 'S' && g->xmap.map[i][j + 1] == 'O' && g->xmap.map[i][j + 2] == ' ')
			g->xmap.header.south = ft_strdup(g->xmap.map[i] + j + 3);
		if (g->xmap.map[i][j] == 'W' && g->xmap.map[i][j + 1] == 'E' && g->xmap.map[i][j + 2] == ' ')
			g->xmap.header.west = ft_strdup(g->xmap.map[i] + j + 3);
		if (g->xmap.map[i][j] == 'E' && g->xmap.map[i][j + 1] == 'A' && g->xmap.map[i][j + 2] == ' ')
			g->xmap.header.east = ft_strdup(g->xmap.map[i] + j + 3);
		if (g->xmap.map[i][j] == 'F' && g->xmap.map[i][j + 1] == ' ')
			g->xmap.header.floor = ft_strdup(g->xmap.map[i] + j + 2);
		if (g->xmap.map[i][j] == 'C' && g->xmap.map[i][j + 1] == ' ')
			g->xmap.header.cell = ft_strdup(g->xmap.map[i] + j + 2);
		if (g->xmap.header.north && g->xmap.header.south && g->xmap.header.west &&
			g->xmap.header.east && g->xmap.header.floor && g->xmap.header.cell)
			return (i);
		i++;
	}
	return (-1);
}
