/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:17:56 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/16 17:18:54 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include "mlx.h"
#include "utils/chars.h"
#include "utils/pointers.h"
#include "utils/strings.h"
#include "utils/print.h"
#include "utils/files.h"
#include "utils/split.h"
#include "utils/vector3.h"
#include "parsing/pheader.h"
#include "parsing/pbody.h"
#include "parsing/pchars.h"
#include "global.h"
#include "textures.h"
#include "hooks.h"

static int	ft_error(t_global *g, char *s)
{
	ft_puterr(s);
	ft_global_free(g);
	return (1);
}

static bool	ft_is_finish(char *array, int i)
{
	while (ft_isnline(array[i]))
		i++;
	if (!array[i])
		return (true);
	return (false);
}

static bool	ft_check_line(char *array)
{
	int	i;

	i = ft_header_size(array);
	if (i < 0)
		return (false);
	while (ft_isnline(array[i]))
		i++;
	while (array[i])
	{
		if (!(ft_is_finish(array, i)))
			if (ft_isnline(array[i]) && ft_isnline(array[i + 1]))
				return (false);
		i++;
	}
	return (true);
}

static bool	ft_map_read(t_global *g, char *path)
{
	char		*array;

	if (!ft_read(path, &array))
		return (false);
	if (!(ft_check_line(array)))
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
	if (!ft_minilibx_init(&g.mlx, &g.img, &g.mmap))
		return (ft_error(&g, "Could not create window\n"));
	if (!ft_textures_load(&g.mlx, &g.xpms, &g.map.header))
		return (ft_error(&g, "Could not load textures\n"));
	ft_minilibx_hook(&g);
	mlx_loop(g.mlx.ptr);
	ft_textures_free(&g.mlx, &g.xpms);
	ft_minilibx_free(&g.mlx, &g.img, &g.mmap);
	ft_global_free(&g);
	return (0);
}
