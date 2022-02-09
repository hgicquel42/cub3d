/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:43:55 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 12:58:54 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "minilibx.h"
# include "positions.h" 
# include "player.h"
# include <stdlib.h>

typedef struct s_wall
{
	double	dist;
	int		height;
	int		start;
	int		end;
}	t_wall;

typedef struct s_ray
{
	t_ipos	map;
	t_dpos	pos;
	t_dpos	ray_dist;
	t_dpos	yaw;
	t_dpos	plan;
	t_dpos	delta;
	t_wall	wall;
	int		side;
}	t_ray;

/**
 * @brief init ray from player position
 * 
 * @param ray 
 * @param player 
 */
void	ft_ray_init(t_ray *ray, t_player *player);


/**
 * @brief reinit ray for i
 * 
 * @param ray 
 * @param player 
 * @param offset
 */
void	ft_ray_reinit(t_ray *ray, t_player *player, double offset);

#endif
