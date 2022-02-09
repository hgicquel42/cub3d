/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:43:55 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 16:25:08 by hgicquel         ###   ########.fr       */
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
	t_vec		pos;
	t_vec		yaw;
	t_ipos		tile;
	t_ipos		step;
	t_vec		delta;
	t_vec		sdist;
	bool		side;
}	t_ray;

#endif
