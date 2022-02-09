/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:04:54 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/09 11:21:32 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include "raycast.h"
#include "global.h"
#include "math.h"
#include "./utils/colors.h"
#include "../minilibx/mlx.h"

void	ft_draw_wall(t_global *g, t_img *img, int y, int x)
{
	y = g->ray.wall.start - 1;
	g->s.step = 1.0 * img->h / g->ray.wall.height;
	g->s.cord.x = (int)(g->s.x_wall * (double)img->w);
	if (g->ray.side == 0 && g->ray.yaw.x > 0)
		g->s.cord.x = img->w - g->s.cord.x -1;
	if (g->ray.side == 0 && g->ray.yaw.y < 0)
		g->s.cord.x = img->w - g->s.cord.x -1;
	g->s.pos = (g->ray.wall.start - g->mlx.screen.y / 2
			+ g->ray.wall.height / 2) * g->s.step;
	while (y < g->ray.wall.end)
	{
		g->s.cord.y = floor(g->s.pos);
		g->s.pos += g->s.step;
		if (y < g->mlx.screen.y && x < g->mlx.screen.x)
		{
			g->mlx.img.data[y * g->mlx.img.line / 4 + x]
				= img->data[g->s.cord.y * img->line / 4 + g->s.cord.x];
		}
		y++;
	}
}

void	ft_init_sprite(t_global *g, int y, int x)
{
	if (g->ray.side == 0)
		g->s.x_wall = g->ray.pos.y + g->ray.wall.dist * g->ray.yaw.y;
	else
		g->s.x_wall = g->ray.pos.x + g->ray.wall.dist * g->ray.yaw.x;
	g->s.x_wall -= floor(g->s.x_wall);
	if (g->ray.side == 0 && g->ray.yaw.x < 0)
		ft_draw_wall(g, &g->mlx.north, y, x);
	else if (g->ray.side == 0 && g->ray.yaw.x >= 0)
		ft_draw_wall(g, &g->mlx.south, y, x);
	else if (g->ray.side == 1 && g->ray.yaw.y < 0)
		ft_draw_wall(g, &g->mlx.west, y, x);
	else if (g->ray.side == 1 && g->ray.yaw.y >= 0)
		ft_draw_wall(g, &g->mlx.east, y, x);
}

/**
 * @brief 
 * 
 * @param g 
 * @param i 
 */
void	ft_draw_line(t_global *g, int i)
{
	int	j;

	j = 0;
	while (j < g->ray.wall.start)
	{
		g->mlx.img.data[j * g->mlx.img.line / 4 + i]
			= ft_rgbtohex(g->map.header.floor);
		j++;
	}
	if (j <= g->ray.wall.end)
		ft_init_sprite(g, j, i);
	j = g->ray.wall.end;
	while (j < g->mlx.screen.y)
	{
		g->mlx.img.data[j * g->mlx.img.line / 4 + i]
			= ft_rgbtohex(g->map.header.cell);
		j++;
	}
}

bool	ft_draw(t_global *g)
{
	int	i;

	i = 0;
	while (i < g->mlx.img.w)
	{
		ft_ray_init(g, &g->ray, i);
		ft_launch_ray(g, &g->ray);
		ft_draw_line(g, i);
		i++;
	}
	ft_image_put(&g->mlx);
	return (true);
}
