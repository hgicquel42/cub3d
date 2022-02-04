/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 09:13:37 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 18:28:50 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_address(t_global *g, int i)
{
	g->mlx.img[i].img_data = (int *)mlx_get_data_addr(g->mlx.img[i].img_ptr, &g->mlx.img[i].bpp,
							&g->mlx.img[i].line_size, &g->mlx.img[i].endian);
}

bool	get_texture(t_global *g, char *path, int i)
{
	g->mlx.img[i].img_ptr = mlx_xpm_file_to_image(g->mlx.mlx_ptr, path,
							&g->mlx.img[i].width, &g->mlx.img[i].height);
	if (!g->mlx.img[i].img_ptr)
		return(false);
	get_address(g, i);
	return (true);
}

bool	create_texture(t_global *g)
{
	if ((!get_texture(g, g->xmap.header.north, 0)))
		return (false);
	if ((!get_texture(g, g->xmap.header.south, 1)))
		return (false);
	if ((!get_texture(g, g->xmap.header.east, 2)))
		return (false);
	if ((!get_texture(g, g->xmap.header.west, 3)))
		return (false);
	return (true);
}

void	init_ray(t_global *g)
{
	g->ray.x_cam = (g->ray.i * 2) / 799;
	g->ray.x_pos = (double)g->player.x + 0.5; 
	g->ray.y_pos = (double)g->player.y + 0.5;
	g->ray.x_dir = g->ray.x_dir + g->ray.x_fov * g->ray.x_cam;
	g->ray.y_dir = g->ray.y_dir + g->ray.y_fov * g->ray.x_cam;
	g->ray.x_map = (int)g->ray.x_pos;
	g->ray.y_map = (int)g->ray.y_pos;
	g->player.speed = 0.2;
	g->player.rotate_speed = 0.
}

bool	ray_casting(t_global *g)
{
	g->ray.i = 0;
	while (g->ray.i < 800)
	{
		init_ray(g);
	}
}

bool	run_game(t_global *g)
{
	g->mlx.mlx_ptr = mlx_init();
	if (!g->mlx.mlx_ptr)
		return (false);
	if (!create_texture(g))
		return (false);
	g->mlx.img_ptr = mlx_new_image(g->mlx.mlx_ptr, 800, 600);
	if (!(g->mlx.img_ptr))
		return (false);
	g->mlx.img_adr = (int *)mlx_get_data_addr(g->mlx.img_ptr, &g->mlx.bpp, &g->mlx.line_size, &g->mlx.endian);
	g->mlx.win_ptr = mlx_new_window(g->mlx.mlx_ptr, 800, 600, "Cub3D");
	ray_casting(g);
	//mlx_put_image_to_window(g->mlx.mlx_ptr, g->mlx.win_ptr, g->mlx.img[0].img_ptr, 0, 0);
	//mlx_put_image_to_window(g->mlx.mlx_ptr, g->mlx.win_ptr, g->mlx.img[1].img_ptr, 700, 0);
	//mlx_put_image_to_window(g->mlx.mlx_ptr, g->mlx.win_ptr, g->mlx.img[2].img_ptr, 0, 500);
	//mlx_put_image_to_window(g->mlx.mlx_ptr, g->mlx.win_ptr, g->mlx.img[3].img_ptr, 700, 500);
	//printf("IMG1\nw = %d\nh = %d\nbpp = %d\nl_s = %d\nen = %d\n", g->mlx.img[0].width, g->mlx.img[0].height, g->mlx.img[0].bpp, g->mlx.img[0].line_size, g->mlx.img[0].endian);
	//printf("IMG2\nw = %d\nh = %d\nbpp = %d\nl_s = %d\nen = %d\n", g->mlx.img[1].width, g->mlx.img[1].height, g->mlx.img[1].bpp, g->mlx.img[1].line_size, g->mlx.img[1].endian);
	//printf("IMG3\nw = %d\nh = %d\nbpp = %d\nl_s = %d\nen = %d\n", g->mlx.img[2].width, g->mlx.img[2].height, g->mlx.img[2].bpp, g->mlx.img[2].line_size, g->mlx.img[2].endian);
	//printf("IMG4\nw = %d\nh = %d\nbpp = %d\nl_s = %d\nen = %d\n", g->mlx.img[3].width, g->mlx.img[3].height, g->mlx.img[3].bpp, g->mlx.img[3].line_size, g->mlx.img[3].endian);
	mlx_loop(g->mlx.mlx_ptr);
	return (true);
}