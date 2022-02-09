/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:43:08 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 12:32:09 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

#include "player.h"
#include <math.h>

/**
 * @brief init ray from player position
 * 
 * @param ray 
 * @param player 
 */
void	ft_ray_init(t_ray *ray, t_player *player)
{
	ray->pos.x = player->pos.x + 0.5;
	ray->pos.y = player->pos.y + 0.5;
	ray->yaw.x = 0;
	ray->yaw.y = 0;
	ray->plan.x = -0.66;
	ray->plan.y = 0;
}

static void	ft_ray_reinit_delta(t_ray *ray)
{
	if (ray->yaw.y == 0)
		ray->delta.x = 0;
	else if (ray->yaw.x == 0)
		ray->delta.x = 1;
	else
		ray->delta.x = sqrt(1 + pow(ray->yaw.y, 2) / pow(ray->yaw.x, 2));
	if (ray->yaw.x == 0)
		ray->delta.y = 0;
	else if (ray->yaw.y == 0)
		ray->delta.y = 1;
	else
		ray->delta.y = sqrt(1 + pow(ray->yaw.x, 2) / pow(ray->yaw.y, 2));
}

/**
 * @brief reinit ray for i
 * 
 * @param ray 
 * @param player 
 * @param i 
 * @param w 
 */
void	ft_ray_reinit(t_ray *ray, t_player *player, int i, double w)
{
	double	offset;

	offset = 2 * i / w - 1;
	ray->yaw.x = player->yaw.x + ray->plan.x * offset;
	ray->yaw.y = player->yaw.y + ray->plan.y * offset;
	ft_ray_reinit_delta(ray);
}
