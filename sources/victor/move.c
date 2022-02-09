/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:27:20 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/09 07:08:26 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

#include "raycast.h"
#include "global.h"
#include <math.h>
#include <stdio.h>

/**
 * @brief manage move on x 
 * 
 * @param g 
 */
void	ft_move_x(t_global *g)
{
	if (g->player.move.x == 1)
	{
		if (g->map.body[(int)(g->ray.pos.x
			+ (g->player.yaw.x * g->player.speed * 2))][(int)g->ray.pos.y] == '0')
			g->ray.pos.x += g->player.yaw.x * g->player.speed;
		if (g->map.body[(int)(g->ray.pos.x)][(int)(g->ray.pos.y
			+ (g->player.yaw.y * g->player.speed * 2))] == '0')
			g->ray.pos.y += g->player.yaw.y * g->player.speed;
	}
	if (g->player.move.x == -1)
	{
		if (g->map.body[(int)(g->ray.pos.x
			- (g->player.yaw.x * g->player.speed * 2))][(int)g->ray.pos.y] == '0')
			g->ray.pos.x -= g->player.yaw.x * g->player.speed;
		if (g->map.body[(int)(g->ray.pos.x)][(int)(g->ray.pos.y
			- (g->player.yaw.y * g->player.speed * 2))] == '0')
			g->ray.pos.y -= g->player.yaw.y * g->player.speed;
	}
}

/**
 * @brief manage move on y
 * 
 * @param g 
 */
void	ft_move_y(t_global *g)
{
	if (g->player.move.y == 1)
	{
		if (g->map.body[(int)(g->ray.pos.x
			+ (g->player.yaw.y * g->player.speed * 2))][(int)g->ray.pos.y] == '0')
			g->ray.pos.x += g->player.yaw.y * g->player.speed;
		if (g->map.body[(int)(g->ray.pos.x)][(int)(g->ray.pos.y
			- (g->player.yaw.x * g->player.speed * 2))] == '0')
			g->ray.pos.y -= g->player.yaw.x * g->player.speed;
	}
	if (g->player.move.y == -1)
	{
		if (g->map.body[(int)(g->ray.pos.x
			- (g->player.yaw.y * g->player.speed * 2))][(int)g->ray.pos.y] == '0')
			g->ray.pos.x -= g->player.yaw.y * g->player.speed;
		if (g->map.body[(int)(g->ray.pos.x)][(int)(g->ray.pos.y
			+ (g->player.yaw.x * g->player.speed * 2))] == '0')
			g->ray.pos.y += g->player.yaw.x * g->player.speed;
	}
}

void	ft_rotate2(t_global *g, double old_yaw_x, double old_plan_x)
{
	if (g->player.rotate == -1)
	{
		g->player.yaw.x = old_yaw_x * cos(-g->player.rot_speed)
			- g->player.yaw.y * sin(-g->player.rot_speed);
		g->player.yaw.y = old_yaw_x * sin(-g->player.rot_speed)
			+ g->player.yaw.y * cos(-g->player.rot_speed);
		g->ray.plan.x = old_plan_x * cos(-g->player.rot_speed)
			- g->ray.plan.y * sin(-g->player.rot_speed);
		g->ray.plan.y = old_plan_x * sin(-g->player.rot_speed)
			+ g->ray.plan.y * cos(-g->player.rot_speed);
	}
}

/**
 * @brief manage rotation
 * 
 * @param g 
 */
void	ft_rotate(t_global *g)
{
	double	old_plan_x;
	double	old_yaw_x;

	old_plan_x = g->ray.plan.x;
	old_yaw_x = g->player.yaw.x;
	if (g->player.rotate == 1)
	{
		g->player.yaw.x = old_yaw_x * cos(g->player.rot_speed)
			- g->player.yaw.y * sin(g->player.rot_speed);
		g->player.yaw.y = old_yaw_x * sin(g->player.rot_speed)
			+ g->player.yaw.y * cos(g->player.rot_speed);
		g->ray.plan.x = old_plan_x * cos(g->player.rot_speed)
			- g->ray.plan.y * sin(g->player.rot_speed);
		g->ray.plan.y = old_plan_x * sin(g->player.rot_speed)
			+ g->ray.plan.y * cos(g->player.rot_speed);
	}
	ft_rotate2(g, old_yaw_x, old_plan_x);
}
