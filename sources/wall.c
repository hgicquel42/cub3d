/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:07:07 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/11 14:08:07 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall.h"

#include <math.h>
#include "raycast.h"
#include "image.h"

static double	ft_wall_x(t_ray *ray)
{
	double	x;

	if (ray->side == RSIDE_NORTH || ray->side == RSIDE_SOUTH)
		x = ray->pos.y + ray->dist * ray->yaw.y;
	else
		x = ray->pos.x + ray->dist * ray->yaw.x;
	x -= floor(x);
	return (x);
}

/**
 * @brief calculate wall height
 * 
 * @param ray 
 * @param img 
 * @return t_wall 
 */
t_wall	ft_wall(t_ray *ray, t_img *img, t_img *xpm, int i)
{
	t_wall	wall;

	wall.i = i;
	wall.t = xpm;
	wall.h = img->h / ray->dist;
	wall.b = (img->h / 2) - (wall.h / 2);
	if (wall.b < 0)
		wall.b = 0;
	wall.e = (img->h / 2) + (wall.h / 2);
	if (wall.e > img->h)
		wall.e = img->h - 1;
	wall.x = ft_wall_x(ray);
	return (wall);
}
