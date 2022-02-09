/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:49:02 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 12:36:35 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

#include <stdbool.h>
#include <stdio.h>
#include "mlx.h"
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
static bool	ft_texture_load(void *mlx, char *path, t_img *img)
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
bool	ft_textures_load(t_mlx *mlx, t_xpms *xpms, t_header *header)
{
	if (!ft_texture_load(mlx->ptr, header->north, &xpms->north))
		return (false);
	if (!ft_texture_load(mlx->ptr, header->south, &xpms->south))
		return (false);
	if (!ft_texture_load(mlx->ptr, header->east, &xpms->east))
		return (false);
	if (!ft_texture_load(mlx->ptr, header->west, &xpms->west))
		return (false);
	return (true);
}

/**
 * @brief free textures
 * 
 * @param mlx 
 * @param xpms 
 */
void	ft_textures_free(t_mlx *mlx, t_xpms *xpms)
{
	mlx_destroy_image(mlx->ptr, xpms->north.ptr);
	mlx_destroy_image(mlx->ptr, xpms->south.ptr);
	mlx_destroy_image(mlx->ptr, xpms->east.ptr);
	mlx_destroy_image(mlx->ptr, xpms->west.ptr);
}
