/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:18:31 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/03 13:39:40 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_len(t_global *g)
{
	int		len;
	int		ret;
	char	buff[1];

	len = 0;
	ret = 1;
	while ((ret = read(g->file, buff, 1)) > 0)
		len++;
	if (ret < 0)
		return (-1);
	if (close (g->file) < 0)
		return (-1);
	if ((g->file = open(g->path, O_RDONLY)) < 1)
		return (-1);
	return (len);
}

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

char	**create_map(t_global *g)
{
	char	**map;
	char	*buff;

	if ((g->len = map_len(g) + 1) < 1)
		return (NULL);
	if (!(buff = malloc(sizeof(char) * g->len)))
		return (NULL);
	read(g->file, buff, g->len - 1);
	buff[g->len] = '\0';
	map = ft_split(buff, '\n');
	return (map);
}
