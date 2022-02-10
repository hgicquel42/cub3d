/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:19:19 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 15:26:28 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

#include <math.h>
#include "global.h"
#include "raycast2.h"
#include "utils/numbers.h"
#include "utils/vector3.h"
#include "parsing/pchars.h"

/**
 * @brief smoothly increase or decrease x value
 * 
 * @param x 
 * @return double 
 */
static double	ft_smooth(double x)
{
	if (x > 0)
		return (ft_minf(0, x - 0.001));
	if (x < 0)
		return (ft_maxf(0, x + 0.001));
	return (x);
}

/**
 * @brief move
 * 
 * @param g 
 * @param player 
 */
void	ft_loop_move(t_global *g, t_player *p)
{
	t_vec		axis;
	t_vec		move;
	t_ray		ray;

	axis = ft_vecmove(p->yaw, p->move);
	ray = ft_ray(p->pos, axis);
	ft_ray_launch(&ray, g->map.body);
	if (g->keys.shift)
		move = ft_vecmul(axis, 0.2);
	else
		move = ft_vecmul(axis, 0.1);
	if (ft_veclen(move) > ray.dist)
		return ;
	p->move.x = ft_smooth(p->move.y);
	p->move.y = ft_smooth(p->move.y);
	p->pos = ft_vecadd(p->pos, move);
}

/**
 * @brief rotate
 * 
 * @param g 
 * @param player 
 */
void	ft_loop_rotate(t_global *g, t_player *player)
{
	t_vec	old;
	double	val;

	if (!player->rotate)
		return ;
	old = g->player.yaw;
	val = g->player.rotate * 0.1;
	g->player.yaw.x = old.x * cos(val) - old.y * sin(val);
	g->player.yaw.y = old.x * sin(val) + old.y * cos(val);
	g->player.rotate = ft_smooth(g->player.rotate);
}
