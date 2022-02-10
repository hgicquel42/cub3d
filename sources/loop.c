/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:44:09 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 11:28:07 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "global.h"
#include "draw.h"
#include "raycast2.h"
#include "math.h"
#include "utils/vector3.h"
#include "utils/numbers.h"

t_vec	ft_cam(t_player *player)
{
	return (ft_vecmul(ft_vecperpn(player->yaw), 0.60));
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
		ft_draw_column(g, &ray, &wall, i);
		i++;
	}
}

void	ft_loop_move(t_global *g)
{
	t_vec	old;
	t_vec	res;
	// int		new_x;
	// int		new_y;
	double	val;

	// new_x = floor(g->player.pos.x + 0.1);
	// new_y = floor(g->player.pos.y + 0.1);
	if (g->player.move.x)
	{
		val = g->player.move.x * 0.1;
		if (g->keys.shift)
			val *= 2;
		res = ft_vecmul(g->player.yaw, val);
		old = g->player.pos;
		// if (g->map.body[(int)(g->player.pos.x + (g->player.yaw.x * val * 2))][(int)g->player.pos.y] == '0'
			// && g->map.body[(int)g->player.pos.x][(int)(g->player.pos.y + (g->player.yaw.y * val * 2))] == '0')
		g->player.pos = ft_vecadd(g->player.pos, res);
		//if (g->map.body[(int)g->player.pos.x][(int)(g->player.pos.y + (g->player.yaw.y * val * 2))] == '0')
		//	g->player.pos = ft_vecadd(g->player.pos, ft_vecmul(g->player.yaw, g->player.move.y * 0.1));
		if (g->map.body[(int)g->player.pos.x][(int)g->player.pos.y] == '1')
			g->player.pos = old;
		//printf("Px = %d Py = %d\n", (int)(g->player.pos.x), (int)(g->player.pos.y));
		//printf("Nx = %d Ny = %d\n", new_x, new_y);
		//printf("P_map = %c\n", g->map.body[(int)g->player.pos.x][(int)g->player.pos.y]);
		//printf("N_map = %c\n", g->map.body[new_x][new_y]);
		// printf("X_map = %c\n", g->map.body[(int)(g->player.pos.x + (g->player.yaw.x * val * 2))][(int)g->player.pos.y]);
		// printf("Y_map = %c\n", g->map.body[(int)g->player.pos.x][(int)(g->player.pos.y + (g->player.yaw.y * val * 2))]);
		if (g->player.move.x > 0)
			g->player.move.x = ft_minf(0, g->player.move.x - 0.001);
		if (g->player.move.x < 0)
			g->player.move.x = ft_maxf(0, g->player.move.x + 0.001);
	}
	if (g->player.move.y)
	{
		val = g->player.move.y * 0.1;
		res = ft_vecmul(g->player.yaw, val);
		res = ft_vecperpp(res);
		old = g->player.pos;
		//if (g->map.body[(int)(g->player.pos.x + (g->player.yaw.x * val * 2))][(int)g->player.pos.y] == '0')
		//	g->player.pos = ft_vecadd(g->player.pos, ft_vecmul(g->player.yaw, g->player.move.x * 0.1));
		// if (g->map.body[(int)(g->player.pos.x + (g->player.yaw.x * val * 2))][(int)g->player.pos.y] == '0'
			// && g->map.body[(int)g->player.pos.x][(int)(g->player.pos.y + (g->player.yaw.y * val * 2))] == '0')
		g->player.pos = ft_vecadd(g->player.pos, res);
	if (g->map.body[(int)g->player.pos.x][(int)g->player.pos.y] == '1')
			g->player.pos = old;
		// printf("Px = %d Py = %d\n", (int)(g->player.pos.x), (int)(g->player.pos.y));
		// printf("Nx = %d Ny = %d\n", new_x, new_y);
		//printf("P_map = %c\n", g->map.body[(int)g->player.pos.x][(int)g->player.pos.y]);
		//printf("N_map = %c\n", g->map.body[new_x][new_y]);
		if (g->player.move.y > 0)
			g->player.move.y = ft_minf(0, g->player.move.y - 0.001);
		if (g->player.move.y < 0)
			g->player.move.y = ft_maxf(0, g->player.move.y + 0.001);
	}
	if (g->player.rotate)
	{
		old = g->player.yaw;
		val = g->player.rotate * 0.1;
		res.x = old.x * cos(val) - old.y * sin(val);
		res.y = old.x * sin(val) + old.y * cos(val);
		g->player.yaw.x = res.x;
		g->player.yaw.y = res.y;
		if (g->player.rotate > 0)
			g->player.rotate = ft_minf(0, g->player.rotate - 0.001);
		if (g->player.rotate < 0)
			g->player.rotate = ft_maxf(0, g->player.rotate + 0.001);
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
	ft_loop_keys(g);
	ft_loop_move(g);
	ft_loop_draw(g);
	ft_image_put(&g->mlx, &g->img);
	return (true);
}
