/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:43:08 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 19:39:52 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

#include "minilibx.h"
#include "global.h"

/**
 * @brief init raycast
 * 
 * @param ray ray struct
 */
void	ft_ray_init(t_global *g, t_ray *ray, int i)
{
	int	camerax;

	camerax = 2 * i / ((double) g->mlx.img.w) - 1;
	ray->pos.x = g->player.pos.x;
	ray->pos.y = g->player.pos.y;
	ray->yaw.x = g->player.yaw.x + 0.9 * camerax;
	ray->yaw.y = g->player.yaw.y + 0.9 * camerax;
}
