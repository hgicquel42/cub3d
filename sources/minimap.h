/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:01:50 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/11 15:22:13 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "global.h"

/**
 * @brief create minimap at each frame
 * 
 * @param g 
 */
void	ft_loop_minimap(t_global *g);

/**
 * @brief print mini_map on screen
 * 
 * @param g 
 * @param map 
 * @param pos 
 * @param play 
 */
void	ft_print_map(t_global *g, t_img *map, t_pos pos, t_pos play);

/**
 * @brief Check if map can be display
 * 
 * @param g 
 * @param i 
 * @param j 
 * @return true 
 * @return false 
 */
bool	ft_check_map(t_global *g, int i, int j);

/**
 * @brief Print one case of minimap
 * 
 * @param map 
 * @param pos 
 * @param color 
 */
void	ft_print_case(t_img *map, t_pos pos, int color);

/**
 * @brief Print player on minimap
 * 
 * @param map 
 * @param pos 
 */
void	ft_print_player(t_img *map, t_pos pos);

#endif
