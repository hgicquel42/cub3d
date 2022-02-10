/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:50:55 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 09:52:37 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "minilibx.h"
# include "raycast.h"
# include "global.h"

/**
 * @brief draw single pixel
 * 
 * @param img img struct
 * @param x pixel x
 * @param y pixel y
 * @param color pixel color
 */
void	ft_draw_pixel(t_img *img, int x, int y, int color);

/**
 * @brief draw column
 * 
 * @param img 
 * @param ray 
 * @param i 
 */
void	ft_draw_column(t_global *g, t_ray *ray, t_wall *wall, int i);

#endif
