/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:29:27 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 16:55:24 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

/**
 * @brief init player
 * 
 * @param player 
 */
void	ft_player_init(t_player *player)
{
	player->yaw.x = 0;
	player->yaw.y = 0;
	player->move.x = 0;
	player->move.y = 0;
	player->rotate = 0;
}
