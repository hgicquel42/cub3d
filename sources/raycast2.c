/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:23:12 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 19:36:13 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast2.h"

#include <math.h>
#include "raycast.h"
#include "global.h"
#include "utils/vector3.h"
#include "parsing/pchars.h"

/**
 * @brief calculate wall
 * 
 * @param g 
 * @param ray 
 */
void	ft_ray_wall(t_ray *ray, t_wall *wall, t_img *img)
{
	if (!ray->side)
		wall->dist = (ray->sdist.x - ray->delta.x);
	else
		wall->dist = (ray->sdist.y - ray->delta.y);
	wall->height = img->h / wall->dist;
	wall->start = (img->h / 2) - (wall->height / 2);
	wall->end = (img->h / 2) + (wall->height / 2);
}

/**
 * @brief loop ray until it hits a wall
 * 
 * @param ray 
 * @param body 
 */
void	ft_ray_loop(t_ray *ray, char **body)
{
	while (!ft_iswall(body[ray->tile.x][ray->tile.y]))
	{
		if (ray->sdist.x < ray->sdist.y)
		{
			ray->sdist.x += ray->delta.x;
			ray->tile.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sdist.y += ray->delta.y;
			ray->tile.y += ray->step.y;
			ray->side = 1;
		}
	}
}

/**
 * @brief init ray tile, delta and side distance
 * 
 * @param ray 
 */
void	ft_ray_init(t_ray *ray)
{
	ray->tile.x = ray->pos.x;
	ray->tile.y = ray->pos.y;
	ray->delta = ft_vecdelta(ray->yaw);
	if (ray->yaw.x < 0)
	{
		ray->step.x = -1;
		ray->sdist.x = (ray->pos.x - ray->tile.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sdist.x = (ray->tile.x + 1.0 - ray->pos.x) * ray->delta.x;
	}
	if (ray->yaw.y < 0)
	{
		ray->step.y = -1;
		ray->sdist.y = (ray->pos.y - ray->tile.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sdist.y = (ray->tile.y + 1.0 - ray->pos.y) * ray->delta.y;
	}
}
