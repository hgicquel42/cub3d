/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:29:54 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 17:26:18 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx.h"

#include <stdbool.h>
#include <stdio.h>
#include "../minilibx/mlx.h"
#include "utils/pointers.h"
#include "global.h"

/**
 * @brief init image data address
 * 
 * @param img img struct
 * @return false if failed
 */
bool	ft_image_init(t_img *img)
{
	img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->line, &img->end);
	if (!img->data)
		return (false);
	return (true);
}

/**
 * @brief load xpm into minilibx
 * 
 * @param mlx mlx ptr
 * @param path file
 * @param img img struct
 * @return false if failed
 */
bool	ft_minilibx_load(void *mlx, char *path, t_img *img)
{
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->ptr)
		return (false);
	if (!ft_image_init(img))
		return (false);
	return (true);
}

/**
 * @brief init minilibx
 * 
 * @param mlx mlx struct
 * @return false if failed
 */
bool	ft_minilibx_init(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (false);
	mlx_get_screen_size(mlx->ptr, &mlx->screen.x, &mlx->screen.y);
	mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->screen.x, mlx->screen.y);
	if (!mlx->img.ptr)
		return (false);
	if (!ft_image_init(&mlx->img))
		return (false);
	mlx->win = mlx_new_window(mlx->ptr, mlx->screen.x, mlx->screen.y, "cub3d");
	if (!mlx->win)
		return (false);
	return (true);
}

/**
 * @brief free minilibx
 * 
 * @param mlx mlx struct
 */
void	ft_minilibx_free(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	ft_free(mlx->ptr);
}
