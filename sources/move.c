/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:19:19 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/11 14:28:21 by hgicquel         ###   ########.fr       */
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
static double	ft_smooth(double x, double s)
{
	if (x > 0)
		return (ft_maxf(0, x - s));
	if (x < 0)
		return (ft_minf(0, x + s));
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
	t_vec		move;
	t_ray		ray;

	move = ft_vecmove(p->yaw, p->move);
	if (g->keys.shift)
		move = ft_vecmul(move, 0.2);
	else
		move = ft_vecmul(move, 0.1);
	ray = ft_ray(p->pos, ft_vecnorm(move));
	ft_ray_launch(&ray, g->map.body);
	while (ft_veclen(move) > ray.dist)
	{
		move = ft_vecsub(move, ft_vecmul(ray.wall, ft_vecdot(move, ray.wall)));
		ray = ft_ray(p->pos, ft_vecnorm(move));
		ft_ray_launch(&ray, g->map.body);
	}
	p->move.x = ft_smooth(p->move.x, 0.5);
	p->move.y = ft_smooth(p->move.y, 0.5);
	p->pos = ft_vecadd(p->pos, move);
}

/**
 * @brief rotate
 * 
 * @param g 
 * @param player 
 */
void	ft_loop_rotate(t_global *g, t_player *p)
{
	t_vec	old;
	double	val;

	(void)g;
	old = p->yaw;
	val = p->rotate * 0.15;
	p->yaw.x = old.x * cos(val) - old.y * sin(val);
	p->yaw.y = old.x * sin(val) + old.y * cos(val);
	p->rotate = ft_smooth(p->rotate, 0.5);
}
