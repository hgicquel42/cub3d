/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:28:18 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 11:34:50 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "positions.h"

# define ROTATION_SPEED 0.06
# define MOVEMENT_SPEED 0.3

typedef struct s_player
{
	t_dpos	pos;
	t_dpos	yaw;
	t_ipos	move;
	int		rotate;
	double	speed;
	double	rot_speed;
}	t_player;

/**
 * @brief init player
 * 
 * @param player 
 */
void	ft_player_init(t_player *player);

#endif
