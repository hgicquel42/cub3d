/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:47:55 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/09 07:16:34 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast_init.h"

#include "raycast.h"
#include <stdio.h>

/**
 * @brief init player pos and ray dir one time on start
 * 
 * @param g 
 */
void	ft_first_ray_init(t_global *g)
{
	g->ray.pos.x = (double)g->player.pos.x + 0.5;
	g->ray.pos.y = (double)g->player.pos.y + 0.5;
	g->player.yaw.x = 0;
	g->player.yaw.y = -1;
	g->ray.plan.x = -0.66;
	g->ray.plan.y = 0;
	g->ray.yaw.x = 0;
	g->ray.yaw.y = 0;
	g->player.speed = 0.3;
	g->player.rot_speed = 0.033 * 1.8;
	g->player.move.x = 0;
	g->player.move.y = 0;
	g->player.rotate = 0;
}

/**
 * @brief init delta with sqrt
 * 
 * @param ray 
 */

void	ft_init_delta(t_ray *ray)
{
	if (ray->yaw.y == 0)
		ray->delta.x = 0;
	else if (ray->yaw.x == 0)
		ray->delta.x = 1;
	else
	{
		ray->delta.x = sqrt(1 + (ray->yaw.y * ray->yaw.y)
				/ (ray->yaw.x * ray->yaw.x));
	}
	if (ray->yaw.x == 0)
		ray->delta.y = 0;
	else if (ray->yaw.y == 0)
		ray->delta.y = 1;
	else
	{
		ray->delta.y = sqrt(1 + (ray->yaw.x * ray->yaw.x)
				/ (ray->yaw.y * ray->yaw.y));
	}
}

/**
 * @brief init raycast
 * 
 * @param ray ray struct
 */
void	ft_ray_init(t_global *g, t_ray *ray, int i)
{
	double	camerax;

	camerax = 2 * i / (double)g->mlx.screen.x - 1;
	g->ray.wall.dist = 0;
	ray->yaw.x = g->player.yaw.x + ray->plan.x * camerax;
	ray->yaw.y = g->player.yaw.y + ray->plan.y * camerax;
	ray->map.x = (int)g->player.pos.x;
	ray->map.y = (int)g->player.pos.y;
	ft_init_delta(ray);
}
