/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:44:09 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 17:31:09 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "global.h"
#include "draw.h"
#include "raycast2.h"
#include "utils/vector3.h"

t_vec	ft_cam(t_player *player)
{
	return (ft_vecmul(ft_vecperpp(player->yaw), 0.60));
}

t_vec	ft_ray(t_vec cam, t_player *player, double o)
{
	return (ft_vecadd(player->yaw, ft_vecmul(cam, o)));
}

void	ft_loop_draw(t_global *g)
{
	int		i;
	double	o;
	t_vec	cam;
	t_ray	ray;
	t_wall	wall;

	cam = ft_cam(&g->player);
	i = 0;
	while (i < g->img.w)
	{
		o = 2 * i / (double) g->img.w - 1;
		ray.pos = g->player.pos;
		ray.yaw = ft_ray(cam, &g->player, o);
		ft_ray_init(&ray);
		ft_ray_loop(&ray, g->map.body);
		ft_ray_wall(&ray, &wall, &g->img);
		ft_draw_column(&g->img, &wall, i);
		i++;
	}
}

void	ft_loop_move(t_global *g)
{
	t_vec	old;
	t_vec	res;
	int		val;

	if (g->player.rotate)
	{
		old = g->player.yaw;
		val = g->player.rotate;
		res.x = old.x * cos(val * ROT_SPEED) - old.y * sin(val * ROT_SPEED);
		res.y = old.x * sin(val * ROT_SPEED) + old.y * cos(val * ROT_SPEED);
		g->player.yaw.x = res.x;
		g->player.yaw.y = res.y;
	}
}

/**
 * @brief frame loop (60Hz)
 * 
 * @param g global
 * @return false if failed
 */
bool	ft_loop(t_global *g)
{
	ft_loop_move(g);
	ft_loop_draw(g);
	ft_image_put(&g->mlx, &g->img);
	return (true);
}
