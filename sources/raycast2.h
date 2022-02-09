/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:22:40 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 12:42:18 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST2_H
# define RAYCAST2_H

# include "raycast.h"
# include "global.h"

/**
 * @brief manage ray casting
 * 
 * @param g 
 * @return int 
 */
bool	ft_ray_cast(t_global *g);

/**
 * @brief Launch ray until he hit a wall
 * 
 * @param ray 
 * @param x_step 
 * @param y_step 
 */
void	ft_ray_loop(t_global *g, t_ray *ray, int x_step, int y_step);

/**
 * @brief calcul dist of ray from view to wall
 * 
 * @param g 
 * @param ray 
 * @param x_step 
 * @param y_step 
 */
void	ft_ray_dist(t_global *g, t_ray *ray, int x_step, int y_step);

/**
 * @brief Create and launch ray for ray casting
 * 
 * @param g 
 * @param ray 
 */
void	ft_ray_launch(t_global *g, t_ray *ray);

#endif
