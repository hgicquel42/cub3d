/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:43:36 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 13:12:10 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include "header.h"
# include "minilibx.h"
# include "positions.h" 
# include "raycast.h"
# include "player.h"
# include "textures.h"

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
	t_sprite	s;
	t_img		img;
	t_xpms		xpms;
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
