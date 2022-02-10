/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:19:14 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 15:24:18 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "global.h"

/**
 * @brief move
 * 
 * @param g 
 * @param player 
 */
void	ft_loop_move(t_global *g, t_player *p);

/**
 * @brief rotate
 * 
 * @param g 
 * @param player 
 */
void	ft_loop_rotate(t_global *g, t_player *player);

#endif
