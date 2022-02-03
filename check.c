/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:23:03 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/03 13:59:47 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
int	check_color(char *color)
{
	int	i;
	int	j;
	int	tmp;
	int	b;

	i = 0;
	j = 0;
	b = 0;
	while (color[i] == ' ')
		i++;
	while (color[i])
	{
		j = 0;
		tmp = 0;
		while (color[i + j] != ',')
			j++;
		while (tmp < j)
		{
			if (b != 2 && (!ft_isdigit(color[i + tmp])))
				return (-1);
			tmp++;
		}
		tmp = 0;
		while (tmp < j)
		{
			if (tmp < 2)
			{
				if (color[i + tmp] > '2')
					return (-1);
			}
			else
			{
				if (color[i + tmp - 1] > '2' && color[i + tmp] > '5')
					return (-1);
			}
			tmp++;
		}
		if (color[i] > '2' ||
			(color[i] == '2' && color[i + 1] > '2') ||
			(color[i] == '2' && color[i + 1] == '2' && color[i + 2] > '5'))
			return (-1);
		i += j;
		if (b != 2 && color[i] != ',')
			return (-1);
		i++;
		b++;
	}
	return (0);
}*/

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
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (j == 0 || i == g->i_start_map|| j == (ft_strlen(g->map[i]) - 1) || i == (map_size(g->map) - 1))
			{
				if (g->map[i][j] != '1')
					return (-1);
			}
			if (check_char(g->map[i][j]) < 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*cut_space(char *str) // Gerer si y a des espace dans le path
{
	int	i;
	int	j;
	int	k;
	int	b;

	i = 0;
	j = 0;
	b = 0;
	while (str[i] && str[i] == ' ')
		i++;
	j = i;
	while (b == 0)
	{
		k = 0;
		while (str[j] && str[j] != ' ')
			j++;
		while (str[j + k] && str[j + k] == ' ')
			k++;
		if (str[j + k] == '\0')
			b = 1;
		j++;
	}
	return (ft_substr(str, i, j));
}

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
		if (ft_atoi(rgb[i]) > 225)
			return (-1);
		i++;
	}
	return (0);
}

int	check_map_info(t_global *g)
{
	g->no = NULL;
	g->so = NULL;
	g->ea = NULL;
	g->we = NULL;
	g->floor_color = NULL;
	g->cell_color = NULL;
	if ((g->i_start_map = get_map_info(g) + 1) < 1)
		return(-1);
	if (!(g->no = cut_space(g->no)))
		return (-1);
	if (!(g->so = cut_space(g->so)))
		return (-1);
	if (!(g->we = cut_space(g->we)))
		return (-1);
	if (!(g->ea = cut_space(g->ea)))
		return (-1);
	if (!(g->floor_color = cut_space(g->floor_color)))
		return (-1);
	if (!(g->cell_color = cut_space(g->cell_color)))
		return (-1);
	// COMPTER LES VIRGULES trimer les espaces de la fin PUIS split PAR VIRGULE ENSUITE ATOI CHECK LES VALEURS
	if (check_color(g->floor_color) < 0)
		return (-1);
	if (check_color(g->cell_color) < 0)
		return (-1);
	return (0);
}

bool	check_map(t_global *g)
{
	if (check_map_info(g) < 0)
		return (false);
	add_wall(g);
	if (check_wall_char(g) < 0)
		return (false);
	return (true);
}
