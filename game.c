/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 09:13:37 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 10:59:57 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "cub3d.h"
# include "minilibx-linux/mlx.h"

#include <stdio.h>

void	create_image(t_global *g)
{
	int	i;

	i = 0;
	g->mlx.img[0].img_ptr = mlx_new_image(g->mlx.mlx_ptr, 400, 100);
	g->mlx.img[0].img_data = mlx_get_data_addr(g->mlx.img[0].img_ptr, &g->mlx.img[0].bpp, &g->mlx.img[0].line_size, &g->mlx.img[0].endian);
	while (i < (10 * 4 + 4 * g->mlx.img[0].line_size * 10))
	{
		if (i % 4 == 0)
			g->mlx.img[0].img_data[i] = '1';
		else
			g->mlx.img[0].img_data[i] = '1';
		i++;
	}
	mlx_put_image_to_window(g->mlx.mlx_ptr, g->mlx.win_ptr, g->mlx.img[0].img_ptr, 0, 0);
	return ;
}

int	run_game(t_global *g)
{
	g->mlx.mlx_ptr = mlx_init();
	if (!g->mlx.mlx_ptr)
		return (-1);
	g->mlx.win_ptr = mlx_new_window(g->mlx.mlx_ptr, 800, 600, "Cub3D");
	create_image(g);
	mlx_loop(g->mlx.mlx_ptr);
	return (0);
}