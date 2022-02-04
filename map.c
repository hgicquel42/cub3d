/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:18:31 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 14:28:24 by hgicquel         ###   ########.fr       */
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

int	get_map_info(t_global *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map.lines[i] != NULL)
	{
		j = 0;
		while (g->map.lines[i][j] == ' ')
			j++;
		if (g->map.lines[i][j] == 'N' && g->map.lines[i][j + 1] == 'O' && g->map.lines[i][j + 2] == ' ')
			g->map.header.north = ft_strdup(g->map.lines[i] + j + 3);
		if (g->map.lines[i][j] == 'S' && g->map.lines[i][j + 1] == 'O' && g->map.lines[i][j + 2] == ' ')
			g->map.header.south = ft_strdup(g->map.lines[i] + j + 3);
		if (g->map.lines[i][j] == 'W' && g->map.lines[i][j + 1] == 'E' && g->map.lines[i][j + 2] == ' ')
			g->map.header.west = ft_strdup(g->map.lines[i] + j + 3);
		if (g->map.lines[i][j] == 'E' && g->map.lines[i][j + 1] == 'A' && g->map.lines[i][j + 2] == ' ')
			g->map.header.east = ft_strdup(g->map.lines[i] + j + 3);
		if (g->map.lines[i][j] == 'F' && g->map.lines[i][j + 1] == ' ')
			g->map.header.floor = ft_strdup(g->map.lines[i] + j + 2);
		if (g->map.lines[i][j] == 'C' && g->map.lines[i][j + 1] == ' ')
			g->map.header.cell = ft_strdup(g->map.lines[i] + j + 2);
		if (g->map.header.north && g->map.header.south && g->map.header.west &&
			g->map.header.east && g->map.header.floor && g->map.header.cell)
			return (i);
		i++;
	}
	return (-1);
}
