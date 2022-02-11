/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:44:09 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/11 12:24:26 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "utils/vector3.h"
#include "utils/numbers.h"
#include "global.h"
#include "draw.h"
#include "raycast2.h"
#include "math.h"
#include "move.h"
#include "minimap.h"

t_vec	ft_cam(t_player *player)
{
	return (ft_vecmul(ft_vecperpn(player->yaw), 0.9));
}

t_vec	ft_yaw(t_vec cam, t_player *player, double o)
{
	return (ft_vecadd(player->yaw, ft_vecmul(cam, o)));
}

void	ft_loop_draw(t_global *g, t_player *p)
{
	int		i;
	double	o;
	t_vec	cam;
	t_vec	yaw;
	t_ray	ray;

	cam = ft_cam(p);
	i = 0;
	while (i < g->img.w)
	{
		o = 2 * i / (double) g->img.w - 1;
		yaw = ft_yaw(cam, p, o);
		ray = ft_ray(p->pos, yaw);
		ft_ray_launch(&ray, g->map.body);
		ft_draw_column(g, &ray, i);
		i++;
	}
}

void	ft_loop_keys(t_global *g)
{
	if (g->keys.w)
		g->player.move.x = 1;
	if (g->keys.s)
		g->player.move.x = -1;
	if (g->keys.a)
		g->player.move.y = 1;
	if (g->keys.d)
		g->player.move.y = -1;
	if (g->keys.al)
		g->player.rotate = 1;
	if (g->keys.ar)
		g->player.rotate = -1;
}

/**
 * @brief frame loop (60Hz)
 * 
 * @param g global
 * @return false if failed
 */
bool	ft_loop(t_global *g)
{
	t_player	*p;

	p = &g->player;
	ft_loop_keys(g);
	ft_loop_move(g, p);
	ft_loop_rotate(g, p);
	ft_loop_draw(g, p);
	ft_image_put(&g->mlx, &g->img);
	ft_minimap(g);
	return (true);
}
