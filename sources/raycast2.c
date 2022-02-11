/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:23:12 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/11 10:06:03 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast2.h"

#include <math.h>
#include "raycast.h"
#include "global.h"
#include "utils/numbers.h"
#include "utils/vector3.h"
#include "parsing/pchars.h"

typedef struct s_path
{
	t_pos	tile;
	t_pos	step;
}	t_path;

static t_path	ft_path(t_ray *ray)
{
	t_path	path;

	path.tile.x = ray->pos.x;
	path.tile.y = ray->pos.y;
	path.step.x = ft_sign(ray->yaw.x);
	path.step.y = ft_sign(ray->yaw.y);
	return (path);
}

/**
 * @brief init ray current pos
 * 
 * @param ray 
 * @param path 
 */
static void	ft_ray_start(t_ray *ray, t_path path)
{
	if (ray->yaw.x < 0)
		ray->curr.x = (ray->pos.x - path.tile.x) * ray->delta.x;
	else
		ray->curr.x = (path.tile.x + 1.0 - ray->pos.x) * ray->delta.x;
	if (ray->yaw.y < 0)
		ray->curr.y = (ray->pos.y - path.tile.y) * ray->delta.y;
	else
		ray->curr.y = (path.tile.y + 1.0 - ray->pos.y) * ray->delta.y;
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
		ray->curr.y += ray->delta.y;
	}
	else
	{
		path->tile.x += path->step.x;
		ray->curr.x += ray->delta.x;
	}
}

/**
 * @brief calculate wall hit
 * 
 * @param ray 
 * @param xgty 
 */
static void	ft_ray_end(t_ray *ray, bool xgty)
{
	if (xgty)
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
		ray->dist = (ray->curr.y - ray->delta.y);
	}
	else
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
		ray->dist = (ray->curr.x - ray->delta.x);
	}
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
	ft_ray_start(ray, path);
	while (!ft_iswall(body[path.tile.x][path.tile.y]))
	{
		xgty = ray->curr.x > ray->curr.y;
		ft_ray_move(ray, &path, xgty);
	}
	ft_ray_end(ray, xgty);
}
