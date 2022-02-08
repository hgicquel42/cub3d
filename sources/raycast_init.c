/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:47:55 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/08 23:55:05 by vpiamias         ###   ########.fr       */
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
	g->ray.yaw.x = 0;
	g->ray.yaw.y = 0;
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
		ray->delta.x = sqrt(1 + (ray->yaw.y * ray->yaw.y) / (ray->yaw.x * ray->yaw.x));
	if (ray->yaw.x == 0)
		ray->delta.y = 0;
	else if (ray->yaw.y == 0)
		ray->delta.y = 1;
	else
		ray->delta.y = sqrt(1 + (ray->yaw.x * ray->yaw.x) / (ray->yaw.y * ray->yaw.y));
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
	printf("dir_x = %f\tplan_x = %f\tx_cam = %f\n", g->player.pos.x, ray->plan.x, camerax);
	ray->yaw.x = g->player.pos.x + ray->plan.x * camerax;
	ray->yaw.y = g->player.pos.y + ray->plan.y * camerax;
	//printf("r_x = %f\tr_y = %f\n", ray->yaw.x, ray->yaw.y);
	ray->map.x = (int)ray->pos.x;
	ray->map.y = (int)ray->pos.y;
	ft_init_delta(ray);
}