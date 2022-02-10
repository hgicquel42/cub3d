/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:43:55 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 15:05:54 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "minilibx.h"
# include "positions.h" 
# include "player.h"
# include <stdlib.h>

typedef struct s_ray
{
	t_vec		pos;
	t_vec		yaw;
	t_pos		tile;
	t_pos		step;
	t_vec		delta;
	t_vec		sdist;
	double		dist;
	bool		side;
}	t_ray;

/**
 * @brief create ray from pos to yaw
 * 
 * @param pos 
 * @param yaw 
 * @return t_ray 
 */
t_ray	ft_ray(t_vec pos, t_vec yaw);

#endif
