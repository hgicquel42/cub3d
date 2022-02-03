/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:17:56 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/03 19:09:23 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "print.h"
#include <stdio.h>

void	printg(t_global *g)
{
	int	i;

	printf("%s %s %s %s\n", g->no, g->so, g->ea, g->we);
	printf("%s\n", g->floor_color);
	printf("%s\n", g->cell_color);
	i = g->i_start_map;
	while (g->map[i] != NULL)
		printf("%s\n", g->map[i++]);
}

void	printmap(char **p)
{
	while (*p)
	{
		ft_putout(*p++);
		ft_putout("\n");
	}
}

int	ft_error(char *s)
{
	ft_puterr(s);
	return (1);
}

int	main(int argc, char **argv)
{
	t_global	g;
	char		*array;
	char		**lines;

	if (argc != 2)
		return (ft_error("Invalid arguments count\n"));
	if (!ft_strends(argv[1], ".cub"))
		return (ft_error("Invalid filename\n"));
	if (!ft_read(argv[1], &array))
		return (ft_error("Can't read map\n"));
	lines = ft_split(array, '\n');
	if (!lines)
		return (ft_error("Can't parse map\n"));
	g.xmap.lines = lines;
	free(array);
	printmap(lines);
	(void)g;
	// if (!check_map(&g))
	// 	return (1);
	// printg(&g);
	return (0);
}
