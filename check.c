/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:23:03 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 09:04:55 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "cub3d.h"
#include "map.h"

int	check_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (-1);
	return (0);
}

int	check_wall_char(t_global *g)
{
	int	i;
	int	j;

	i = g->i_start_map;
	while (g->xmap.map[i])
	{
		j = 0;
		while (g->xmap.map[i][j])
		{
			if (j == 0 || i == g->i_start_map|| j == (ft_strlen(g->xmap.map[i]) - 1) ||
				i == (map_size(g->xmap.map) - 1))
			{
				if (g->xmap.map[i][j] != '1')
					return (ft_error("Invalid map border\n"));
			}
			if (check_char(g->xmap.map[i][j]) < 0)
				return (ft_error("Invalide char in the map\n"));
			j++;
		}
		i++;
	}
	return (0);
}

#include <stdio.h>

int	check_color(char *color)
{
	char	**rgb;
	int		i;

	i = 0;
	if (!(rgb = ft_split(color, ',')))
		return (-1);
	if (map_size(rgb) != 3)
		return (-1);
	while (rgb[i])
	{
		if (ft_atoi(rgb[i]) > 225 || ft_atoi(rgb[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	check_player(t_global *g)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = g->i_start_map;
	while (g->xmap.map[i])
	{
		j = 0;
		while (g->xmap.map[i][j])
		{
			if (g->xmap.map[i][j] == 'N' || g->xmap.map[i][j] == 'S' || g->xmap.map[i][j] == 'E' ||
				g->xmap.map[i][j] == 'W')
				ret++;
			j++;
		}
		i++;
	}
	if (ret != 1)
		return (ft_error("Invalide player position\n"));
	return (0);
}

int	check_map_info(t_global *g)
{
	if ((g->i_start_map = get_map_info(g) + 1) < 1)
		return(ft_error("Invalid header\n"));
	if (!(g->xmap.header.north = cut_space(g->xmap.header.north)))
		return (-1);
	if (!(g->xmap.header.south = cut_space(g->xmap.header.south)))
		return (-1);
	if (!(g->xmap.header.west = cut_space(g->xmap.header.west)))
		return (-1);
	if (!(g->xmap.header.east = cut_space(g->xmap.header.east)))
		return (-1);
	if (!(g->xmap.header.floor = cut_space(g->xmap.header.floor)))
		return (-1);
	if (!(g->xmap.header.cell = cut_space(g->xmap.header.cell)))
		return (-1);
	if (check_color(g->xmap.header.floor) < 0)
		return (ft_error("Invalide color\n"));
	if (check_color(g->xmap.header.cell) < 0)
		return (ft_error("Invalide color\n"));
	return (0);
}

int	check_map(t_global *g)
{
	if (check_map_info(g) < 0)
		return (-1);
	add_wall(g);
	if (check_wall_char(g) < 0)
		return (-1);
	if (check_player(g) < 0)
		return (-1);
	return (0);
}
