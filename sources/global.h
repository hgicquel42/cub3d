/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:43:36 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 07:02:03 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include "header.h"
# include "minilibx.h"
# include "positions.h" 

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

typedef struct s_player
{
	t_dpos	pos;
	t_dpos	yaw;
	t_ipos	move;
	int		rotate;
	double	speed;
	double	rot_speed;
}	t_player;

typedef struct s_map
{
	t_header	header;
	char		**lines;
	char		**body;
}				t_map;

typedef struct s_sprite
{
	double	x_wall;
	double	step;
	double	pos;
	t_ipos	cord;
}	t_sprite;

typedef struct s_global
{
	t_map		map;
	t_mlx		mlx;
	t_player	player;
	t_ray		ray;
	t_sprite	s;
}				t_global;

/**
 * @brief init global
 * 
 * @param g global
 */
void	ft_global_init(t_global *g);

/**
 * @brief init global
 * 
 * @param g global
 */
void	ft_global_free(t_global *g);

#endif
