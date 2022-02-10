/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:43:08 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 17:20:45 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

#include "utils/vector3.h"

/**
 * @brief create ray from pos to yaw
 * 
 * @param pos 
 * @param yaw 
 * @return t_ray 
 */
t_ray	ft_ray(t_vec pos, t_vec yaw)
{
	t_ray	ray;

	ray.pos = pos;
	ray.yaw = yaw;
	ray.dist = 0;
	ray.delta = ft_vecdelta(yaw);
	return (ray);
}
