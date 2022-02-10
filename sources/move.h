/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:19:14 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 13:30:56 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "global.h"

/**
 * @brief move player at each frame (60Hz)
 * 
 * @param g 
 */
void	ft_loop_move(t_global *g);

#endif
