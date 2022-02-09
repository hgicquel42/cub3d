/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:27:29 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/09 07:03:24 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "global.h"

/**
 * @brief manage move on x 
 * 
 * @param g 
 */
void	ft_move_x(t_global *g);

/**
 * @brief manage move on y
 * 
 * @param g 
 */
void	ft_move_y(t_global *g);

/**
 * @brief manage rotation
 * 
 * @param g 
 */
void	ft_rotate(t_global *g);

#endif