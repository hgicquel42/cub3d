/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:23:12 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 16:35:50 by hgicquel         ###   ########.fr       */
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
		wall->dist = fabs(((double)ray->tile.x - ray->pos.x + (1.0 - (double)ray->step.x) / 2.0) / ray->yaw.x);
	else
		wall->dist = fabs(((double)ray->tile.y - ray->pos.y + (1.0 - (double)ray->step.y) / 2.0) / ray->yaw.y);
	wall->height = (int)(img->h / wall->dist);
	wall->start = img->h / 2 - wall->height / 2;
	if (wall->start < 0)
		wall->start = 0;
	wall->end = wall->height / 2 + img->h / 2;
	if (wall->end >= img->h || wall->end < 0)
		wall->end = img->h - 1;
}

/**
 * @brief loop ray until it hits a wall
 * 
 * @param ray 
 * @param body 
 */
void	ft_ray_loop(t_ray *ray, char **body)
{
	while (1)
	{
		if (ft_iswall(body[ray->tile.x][ray->tile.y]))
			break ;
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
	ray->tile.x = (int)ray->pos.x;
	ray->tile.y = (int)ray->pos.y;
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
