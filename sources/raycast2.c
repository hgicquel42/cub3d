/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:23:12 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/11 12:15:40 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast2.h"

#include <math.h>
#include "raycast.h"
#include "global.h"
#include "path.h"
#include "utils/numbers.h"
#include "utils/vector3.h"
#include "parsing/pchars.h"

/**
 * @brief init ray current pos
 * 
 * @param ray 
 * @param path 
 */
static void	ft_ray_start(t_ray *ray, t_path *path)
{
	if (ray->yaw.x < 0)
		ray->curr.x = (ray->pos.x - path->tile.x) * path->delta.x;
	else
		ray->curr.x = (path->tile.x + 1.0 - ray->pos.x) * path->delta.x;
	if (ray->yaw.y < 0)
		ray->curr.y = (ray->pos.y - path->tile.y) * path->delta.y;
	else
		ray->curr.y = (path->tile.y + 1.0 - ray->pos.y) * path->delta.y;
}

/**
 * @brief move ray and tiles
 * 
 * @param ray 
 * @param path 
 * @param xgty 
 */
static void	ft_ray_move(t_ray *ray, t_path *path, bool xgty)
{
	if (xgty)
	{
		path->tile.y += path->step.y;
		ray->curr.y += path->delta.y;
	}
	else
	{
		path->tile.x += path->step.x;
		ray->curr.x += path->delta.x;
	}
}

/**
 * @brief calculate wall hit on x
 * 
 * @param ray 
 * @param path 
 */
static void	ft_ray_end_xgty(t_ray *ray, t_path *path)
{
	if (ray->yaw.y < 0)
	{
		ray->side = RSIDE_WEST;
		ray->wall = ft_vec(0, -1);
	}
	else
	{
		ray->side = RSIDE_EAST;
		ray->wall = ft_vec(0, 1);
	}
	ray->dist = (ray->curr.y - path->delta.y);
}

/**
 * @brief calculate wall hit on y
 * 
 * @param ray 
 * @param path 
 */
static void	ft_ray_end_ygtx(t_ray *ray, t_path *path)
{
	if (ray->yaw.x < 0)
	{
		ray->side = RSIDE_NORTH;
		ray->wall = ft_vec(-1, 0);
	}
	else
	{
		ray->side = RSIDE_SOUTH;
		ray->wall = ft_vec(1, 0);
	}
	ray->dist = (ray->curr.x - path->delta.x);
}

/**
 * @brief loop ray until it hits a wall
 * 
 * @param ray 
 * @param body 
 */
void	ft_ray_launch(t_ray *ray, char **body)
{
	t_path	path;
	bool	xgty;

	path = ft_path(ray);
	ft_ray_start(ray, &path);
	while (!ft_iswall(body[path.tile.x][path.tile.y]))
	{
		xgty = ray->curr.x > ray->curr.y;
		ft_ray_move(ray, &path, xgty);
	}
	if (xgty)
		ft_ray_end_xgty(ray, &path);
	else
		ft_ray_end_ygtx(ray, &path);
}
