/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:17:56 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/03 16:48:56 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "arrays.h"
#include "print.h"
#include <stdio.h>

bool	ft_readmap(char *filename, t_parray *result)
{
	int		file;
	int		length;
	char	*array;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (false);
	if (!ft_seek(file, &length))
		return (false);
	close(file);
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (false);
	array = malloc(length);
	if (!array)
		return (false);
	*result = ft_parray(array, length);
	return (true);
}

int	ft_error(char *s)
{
	ft_puterr(s);
	return (1);
}

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
		return (ft_error("Invalid arguments count\n"));
	if (!ft_strends(argv[1], ".cub"))
		return (ft_error("Invalid filename\n"));
	if (!ft_readmap(argv[1], &g.xmap.raw))
		return (ft_error("Couldn't read map\n"));
	printf("lol\n");
	g.path = argv[1];
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
