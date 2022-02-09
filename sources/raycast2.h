/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:22:40 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 16:34:50 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST2_H
# define RAYCAST2_H

# include "raycast.h"
# include "global.h"

/**
 * @brief calculate wall
 * 
 * @param g 
 * @param ray 
 */
void	ft_ray_wall(t_ray *ray, t_wall *wall, t_img *img);

/**
 * @brief loop ray until it hits a wall
 * 
 * @param ray 
 * @param body 
 */
void	ft_ray_loop(t_ray *ray, char **body);

/**
 * @brief init ray tile, delta and side distance
 * 
 * @param ray 
 */
void	ft_ray_init(t_ray *ray);

#endif
