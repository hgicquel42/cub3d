/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:59:00 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/11 13:29:42 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_H
# define WALL_H

# include "raycast.h"
# include "image.h"

typedef struct s_wall
{
	int		i;
	double	x;
	int		h;
	int		b;
	int		e;
	t_img	*t;
}	t_wall;

/**
 * @brief calculate wall height
 * 
 * @param ray 
 * @param img 
 * @return t_wall 
 */
t_wall	ft_wall(t_ray *ray, t_img *img, t_img *xpm, int i);

#endif
