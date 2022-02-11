/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:12:14 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/11 12:16:12 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

#include "utils/numbers.h"
#include "utils/vector3.h"

/**
 * @brief path for raycast calculus
 * 
 * @param ray 
 * @return t_path 
 */
t_path	ft_path(t_ray *ray)
{
	t_path	path;

	path.tile.x = ray->pos.x;
	path.tile.y = ray->pos.y;
	path.step.x = ft_sign(ray->yaw.x);
	path.step.y = ft_sign(ray->yaw.y);
	path.delta = ft_vecdelta(ray->yaw);
	return (path);
}
