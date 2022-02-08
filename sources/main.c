/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:17:56 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/08 17:41:23 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include "../minilibx/mlx.h"
#include "utils/chars.h"
#include "utils/pointers.h"
#include "utils/strings.h"
#include "utils/print.h"
#include "utils/files.h"
#include "utils/split.h"
#include "parsing/pheader.h"
#include "parsing/body.h"
#include "global.h"
#include "hooks.h"

static int	ft_error(t_global *g, char *s)
{
	ft_puterr(s);
	ft_global_free(g);
	return (1);
}

static bool	ft_map_read(t_global *g, char *path)
{
	char		*array;

	if (!ft_read(path, &array))
		return (false);
	g->map.lines = ft_split(array, ft_isnline);
	ft_free(array);
	if (!g->map.lines)
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_global	g;

	ft_global_init(&g);
	if (argc != 2 || !ft_strends(argv[1], ".cub"))
		return (ft_error(&g, "Invalid arguments\n"));
	if (!ft_map_read(&g, argv[1]))
		return (ft_error(&g, "Can't read map\n"));
	if (!ft_header_parse(&g, g.map.lines, &g.map.header))
		return (ft_error(&g, "Invalid header\n"));
	if (!ft_body_parse(&g, g.map.body))
		return (ft_error(&g, "Invalid body\n"));
	if (!ft_minilibx_init(&g.mlx))
		return (ft_error(&g, "Could not create window\n"));
	if (!ft_minilibx_textures(&g.map.header, &g.mlx))
		return (ft_error(&g, "Could not load textures\n"));
	ft_minilibx_hook(&g);
	mlx_loop(g.mlx.ptr);
	ft_minilibx_free(&g.mlx);
	ft_global_free(&g);
	return (0);
}
