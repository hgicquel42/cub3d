/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:28:18 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 15:33:33 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "utils/vector.h"

typedef struct s_player
{
	t_vec	pos;
	t_vec	yaw;
	t_vec	move;
	int		rotate;
}	t_player;

/**
 * @brief init player
 * 
 * @param player 
 */
void	ft_player_init(t_player *player);

#endif
