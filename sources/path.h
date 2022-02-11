/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:11:55 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/11 12:13:19 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "raycast.h"

typedef struct s_path
{
	t_pos	tile;
	t_pos	step;
	t_vec	delta;
}	t_path;

/**
 * @brief path for raycast calculus
 * 
 * @param ray 
 * @return t_path 
 */
t_path	ft_path(t_ray *ray);

#endif
