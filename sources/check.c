/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:23:03 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 15:31:35 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (-1);
	return (0);
}

int	ft_map_check_border(t_global *g)
{
	int	i;
	int	j;

	i = g->map.header.length;
	while (g->map.lines[i])
	{
		j = 0;
		while (g->map.lines[i][j])
		{
			if (j == 0 || i == g->i_start_map|| j == (ft_strlen(g->map.lines[i]) - 1) ||
				i == (map_size(g->map.lines) - 1))
			{
				if (g->map.lines[i][j] != '1')
					return (ft_error("Invalid map border\n"));
			}
			if (check_char(g->map.lines[i][j]) < 0)
				return (ft_error("Invalide char in the map\n"));
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_header_check_color(char *color)
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

int	ft_map_check_player(t_global *g)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = g->map.header.length;
	while (g->map.lines[i])
	{
		j = 0;
		while (g->map.lines[i][j])
		{
			if (g->map.lines[i][j] == 'N' || g->map.lines[i][j] == 'S' || g->map.lines[i][j] == 'E' ||
				g->map.lines[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	return (count == 1);
}

bool	ft_header_check(t_global *g)
{
	if (!ft_header_check_color(g->map.header.floor))
		return (false);
	if (!ft_header_check_color(g->map.header.cell))
		return (false);
	return (true);
}

bool	ft_map_check(t_global *g)
{
	if (!ft_header_check(g))
		return (false);
	ft_map_add_wall(g);
	if (!ft_map_check_border(g))
		return (false);
	if (!ft_map_check_player(g))
		return (false);
	return (true);
}
