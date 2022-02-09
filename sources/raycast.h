/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:43:55 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 07:12:23 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "global.h"
# include "minilibx.h"
# include "positions.h" 
# include "move.h"
# include <stdlib.h>

/**
 * @brief mange ray_casting
 * 
 * @param g 
 * @return int 
 */
int		ft_ray_cast(t_global *g);

/**
 * @brief Launch ray until he hit a wall
 * 
 * @param ray 
 * @param x_step 
 * @param y_step 
 */
void	ft_advance_ray(t_global *g, t_ray *ray, int x_step, int y_step);

/**
 * @brief calcul dist of ray from view to wall
 * 
 * @param g 
 * @param ray 
 * @param x_step 
 * @param y_step 
 */
void	ft_define_ray_dist(t_global *g, t_ray *ray, int x_step, int y_step);

/**
 * @brief Create and launch ray for ray casting
 * 
 * @param g 
 * @param ray 
 */
void	ft_launch_ray(t_global *g, t_ray *ray);

#endif
