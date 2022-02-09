/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:23:12 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 13:03:22 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast2.h"

#include <math.h>
#include "raycast.h"
#include "global.h"
#include "parsing/pchars.h"

/**
 * @brief calcul dist of ray from view to wall
 * 
 * @param g 
 * @param ray 
 * @param x_step 
 * @param y_step 
 */
void	ft_ray_dist(t_global *g, t_ray *ray, int x_step, int y_step)
{
	if (ray->side == 0)
		ray->wall.dist = fabs(((double)ray->map.x - ray->pos.x + (1.0 - (double)x_step) / 2.0) / ray->yaw.x);
	else
		ray->wall.dist = fabs(((double)ray->map.y - ray->pos.y + (1.0 - (double)y_step) / 2.0) / ray->yaw.y);
	ray->wall.height = (int)(g->img.h / ray->wall.dist);
	ray->wall.start = -ray->wall.height / 2 + g->img.h / 2;
	if (ray->wall.start < 0)
		ray->wall.start = 0;
	ray->wall.end = ray->wall.height / 2 + g->img.h / 2;
	if (ray->wall.end >= g->img.h || ray->wall.end < 0)
		ray->wall.end = g->img.h - 1;
}

/**
 * @brief Launch ray until he hit a wall
 * 
 * @param ray 
 * @param x_step 
 * @param y_step 
 */
void	ft_ray_loop(t_global *g, t_ray *ray, int x_step, int y_step)
{
	while (1)
	{
		if (ft_iswall(g->map.body[ray->map.x][ray->map.y]))
			break ;
		if (ray->ray_dist.x < ray->ray_dist.y)
		{
			ray->ray_dist.x += ray->delta.x;
			ray->map.x += x_step;
			ray->side = 0;
		}
		else
		{
			ray->ray_dist.y += ray->delta.y;
			ray->map.y += y_step;
			ray->side = 1;
		}
	}
	ft_ray_dist(g, ray, x_step, y_step);
}

/**
 * @brief Create and launch ray for ray casting
 * 
 * @param g 
 * @param ray 
 */
void	ft_ray_launch(t_global *g, t_ray *ray)
{
	int	x_step;
	int	y_step;

	if (ray->yaw.x < 0)
	{
		x_step = -1;
		ray->ray_dist.x = (ray->pos.x - ray->map.x) * ray->delta.x;
	}
	else
	{
		x_step = 1;
		ray->ray_dist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->delta.x;
	}
	if (ray->yaw.y < 0)
	{
		y_step = -1;
		ray->ray_dist.y = (ray->pos.y - ray->map.y) * ray->delta.y;
	}
	else
	{
		y_step = 1;
		ray->ray_dist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->delta.y;
	}
	ft_ray_loop(g, ray, x_step, y_step);
}
