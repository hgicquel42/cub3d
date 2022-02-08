/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:49:02 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 18:05:45 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include "../minilibx/mlx.h"
#include "utils/pointers.h"
#include "header.h"
#include "global.h"

/**
 * @brief load xpm into minilibx
 * 
 * @param mlx mlx ptr
 * @param path file
 * @param img img struct
 * @return false if failed
 */
bool	ft_texture_load(void *mlx, char *path, t_img *img)
{
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->w, &img->h);
	if (!img->ptr)
		return (false);
	if (!ft_image_init(img))
		return (false);
	return (true);
}

/**
 * @brief load xpms into minilibx
 * 
 * @param header 
 * @param mlx mlx struct
 * @return false if failed
 */
bool	ft_textures_load(t_header *header, t_mlx *mlx)
{
	if (!ft_texture_load(mlx->ptr, header->north, &mlx->north))
		return (false);
	if (!ft_texture_load(mlx->ptr, header->south, &mlx->south))
		return (false);
	if (!ft_texture_load(mlx->ptr, header->east, &mlx->east))
		return (false);
	if (!ft_texture_load(mlx->ptr, header->west, &mlx->west))
		return (false);
	return (true);
}
