/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:49:38 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/08 22:01:21 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_INIT_H
# define RAYCAST__INIT_H

# include "raycast.h" 
# include "math.h"

/**
 * @brief init raycast
 * 
 * @param ray ray struct
 */
void	ft_ray_init(t_global *g, t_ray *ray, int i);

/**
 * @brief manage raycast
 * 
 * @param g 
 */

void	ft_first_ray_init(t_global *g);

/**
 * @brief init delta with sqrt
 * 
 * @param ray 
 */

void	ft_init_delta(t_ray *ray);

#endif