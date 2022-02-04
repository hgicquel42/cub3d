/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:17:56 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 09:22:40 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include "game.h"

// TO DO CLEAN CODE TRUC PAS COMPRIS SUR POINT H AVEC CHECK.. SINON PREMIERE PARTIE PROJET OK GO EXEC

void	printg(t_global *g)
{
	int	i;

	printf("%s\n%s\n%s\n%s\n", g->xmap.header.north, g->xmap.header.south, g->xmap.header.east, g->xmap.header.west);
	printf("%s\n", g->xmap.header.floor);
	printf("%s\n", g->xmap.header.cell);
	i = g->i_start_map;
	while (g->xmap.map[i] != NULL)
		printf("%s\n", g->xmap.map[i++]);
}

int	ft_error(char *s)
{
	ft_puterr(s);
	return (-1);
}

void	init_global(t_global *g)
{
	g->xmap.header.cell = NULL;
	g->xmap.header.floor = NULL;
	g->xmap.header.north = NULL;
	g->xmap.header.south = NULL;
	g->xmap.header.east = NULL;
	g->xmap.header.west = NULL;
	g->xmap.map = NULL;
}

int	main(int argc, char **argv)
{
	t_global	g;
	char		*array;
	char		**lines;

	if (argc != 2)
		return (ft_error("Invalid arguments count\n"));
	if (ft_strends(argv[1], ".cub") < 0)
		return (ft_error("Invalid filename\n"));
	if (ft_read(argv[1], &array) < 0)
		return (ft_error("Can't read map\n"));
	lines = ft_split(array, '\n');
	if (!lines)
		return (ft_error("Can't parse map\n"));
	init_global(&g);
	g.xmap.map = lines;
	free(array);
	if (check_map(&g) < 0)
	 	return (-1);
	//printg(&g);
	if (run_game(&g) < 0)
		return (-1);
	return (0);
}
