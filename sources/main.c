/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:17:56 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 16:25:31 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO: CLEAN CODE TRUC PAS COMPRIS SUR POINT H AVEC CHECK.. SINON PREMIERE PARTIE PROJET OK GO EXEC

static void	print_header(t_header *header)
{
	printf("%s\n", header->north);
	printf("%s\n", header->south);
	printf("%s\n", header->east);
	printf("%s\n", header->west);
	printf("%s\n", header->cell);
	printf("%s\n", header->floor);
}

static int	ft_error(t_global *g, char *s)
{
	ft_puterr(s);
	ft_global_free(g);
	return (1);
}

bool	ft_readmap(t_global *g, char *filename)
{
	char		*array;

	if (!ft_read(filename, &array))
		return (false);
	g->map.lines = ft_split(array, ft_isnline);
	ft_free(array);
	if (!g->map.lines)
		return (false);
	if (!ft_header(g->map.lines, &g->map.header))
		return (false);
	g->map.body = g->map.lines + g->map.header.length;
	return (true);
}

int	main(int argc, char **argv)
{
	t_global	g;

	ft_global_init(&g);
	if (argc != 2 || !ft_strends(argv[1], ".cub"))
		return (ft_error(&g, "Invalid arguments\n"));
	if (!ft_readmap(&g, argv[1]))
		return (ft_error(&g, "Can't read map\n"));
	print_header(&g.map.header);
	// g.xmap.map = lines;
	// if (check_map(&g) < 0)
	// 	return (1);
	// if (run_game(&g) < 0)
	// 	return (1);
	ft_global_free(&g);
	return (0);
}
