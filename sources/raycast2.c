/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:23:12 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 12:28:29 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast2.h"

#include "raycast.h"
#include "global.h"

/**
 * @brief calcul dist of ray from view to wall
 * 
 * @param g 
 * @param ray 
 * @param x_step 
 * @param y_step 
 */
void	ft_define_ray_dist(t_global *g, t_ray *ray, int x_step, int y_step)
{
	if (ray->side == 0)
	{
		ray->wall.dist = ((double)ray->map.x - ray->pos.x
				+ (1 - (double)x_step) / 2) / ray->yaw.x;
	}
	else
	{
		ray->wall.dist = ((double)ray->map.y - ray->pos.y
				+ (1 - (double)y_step) / 2) / ray->yaw.y;
	}
	ray->wall.height = (int)(g->mlx.screen.y / ray->wall.dist);
	ray->wall.start = -ray->wall.height / 2 + g->mlx.screen.y / 2;
	if (ray->wall.start < 0)
		ray->wall.start = 0;
	ray->wall.end = ray->wall.height / 2 + g->mlx.screen.y / 2;
	if (ray->wall.end >= g->mlx.screen.y || ray->wall.end < 0)
		ray->wall.end = g->mlx.screen.y - 1;
}

/**
 * @brief Launch ray until he hit a wall
 * 
 * @param ray 
 * @param x_step 
 * @param y_step 
 */
void	ft_advance_ray(t_global *g, t_ray *ray, int x_step, int y_step)
{
	while (1)
	{
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
		if (ft_iswall(g->map.body[ray->map.x][ray->map.y]))
			break ;
	}
	ft_define_ray_dist(g, ray, x_step, y_step);
}

/**
 * @brief Create and launch ray for ray casting
 * 
 * @param g 
 * @param ray 
 */
void	ft_launch_ray(t_global *g, t_ray *ray)
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
	ft_advance_ray(g, ray, x_step, y_step);
}
