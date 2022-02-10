/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:43:55 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 17:16:55 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "minilibx.h"
# include "positions.h" 
# include "player.h"
# include <stdlib.h>

# define RSIDE_NORTH 0
# define RSIDE_SOUTH 1
# define RSIDE_EAST 2 
# define RSIDE_WEST 3

typedef struct s_ray
{
	t_vec		pos;
	t_vec		yaw;
	t_vec		delta;
	t_vec		curr;
	double		dist;
	char		side;
	t_vec		wall;
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
