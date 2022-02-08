/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:43:55 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 19:39:01 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "global.h"
# include "minilibx.h"
# include "positions.h" 

typedef struct s_ray
{
	t_ipos	pos;
	t_dpos	yaw;
}	t_ray;

/**
 * @brief init raycast
 * 
 * @param ray ray struct
 */
void	ft_ray_init(t_global *g, t_ray *ray, int i);

#endif
