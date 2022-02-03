/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:18:31 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/03 18:02:29 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_wall(t_global *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == ' ' || g->map[i][j] == '\t')
				g->map[i][j] = '1';
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
	while (g->map[i] != NULL)
	{
		j = 0;
		while (g->map[i][j] == ' ')
			j++;
		if (g->map[i][j] == 'N' && g->map[i][j + 1] == 'O' && g->map[i][j + 2] == ' ')
			g->no = ft_strdup(g->map[i] + j + 3);
		if (g->map[i][j] == 'S' && g->map[i][j + 1] == 'O' && g->map[i][j + 2] == ' ')
			g->so = ft_strdup(g->map[i] + j + 3);
		if (g->map[i][j] == 'W' && g->map[i][j + 1] == 'E' && g->map[i][j + 2] == ' ')
			g->we = ft_strdup(g->map[i] + j + 3);
		if (g->map[i][j] == 'E' && g->map[i][j + 1] == 'A' && g->map[i][j + 2] == ' ')
			g->ea = ft_strdup(g->map[i] + j + 3);
		if (g->map[i][j] == 'F' && g->map[i][j + 1] == ' ')
			g->floor_color = ft_strdup(g->map[i] + j + 2);
		if (g->map[i][j] == 'C' && g->map[i][j + 1] == ' ')
			g->cell_color = ft_strdup(g->map[i] + j + 2);
		if (g->no && g->so && g->ea && g->floor_color && g->cell_color)
			return (i);
		i++;
	}
	return (-1);
}
