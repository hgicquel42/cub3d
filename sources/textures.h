/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:49:53 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 12:18:39 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "minilibx.h"
# include "header.h"
# include "image.h"

typedef struct s_xpms
{
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
}	t_xpms;

/**
 * @brief load xpms into minilibx
 * 
 * @param header 
 * @param mlx mlx struct
 * @return false if failed
 */
bool	ft_textures_load(t_mlx *mlx, t_xpms *xpms, t_header *header);

/**
 * @brief free textures
 * 
 * @param mlx 
 * @param xpms 
 */
void	ft_textures_free(t_mlx *mlx, t_xpms *xpms);

#endif
