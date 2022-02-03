/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:17:56 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/03 14:01:49 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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

int	main(int argc, char **argv)
{
	t_global	g;

	if (argc != 2)
		return (1);
	g.path = argv[1];
	printf("lol\n");
	if (!ft_strends(argv[1], ".cub"))
		return (1);
	g.file = open(argv[1], O_RDONLY);
	if (g.file == -1)
		return (1);
	g.map = create_map(&g);
	if (!g.map)
		return (1);
	if (!check_map(&g))
		return (1);
	printg(&g);
	return (0);
}
