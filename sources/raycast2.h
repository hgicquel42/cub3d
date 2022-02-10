/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:22:40 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 15:10:36 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST2_H
# define RAYCAST2_H

# include "raycast.h"
# include "global.h"

/**
 * @brief launch ray in body
 * 
 * @param ray 
 * @param body 
 */
void	ft_ray_launch(t_ray *ray, char **body);

#endif
