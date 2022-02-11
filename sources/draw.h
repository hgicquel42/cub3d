/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:50:55 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/11 13:44:08 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "minilibx.h"
# include "raycast.h"
# include "global.h"

/**
 * @brief get pixel at (x y)
 * 
 * @param img 
 * @param x 
 * @param y 
 * @return unsigned int* 
 */
unsigned int	*ft_pixel(t_img *img, int x, int y);

/**
 * @brief draw screen column
 * 
 * @param g 
 * @param ray 
 * @param i 
 */
void	ft_draw_column(t_global *g, t_ray *ray, int i);

#endif
