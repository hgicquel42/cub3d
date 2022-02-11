/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:29:54 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/11 15:21:47 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx.h"

#include <stdbool.h>
#include <stdio.h>
#include "mlx.h"
#include "utils/pointers.h"
#include "header.h"
#include "global.h"

/**
 * @brief put image to window
 * 
 * @param mlx mlx
 * @param img img
 */
void	ft_image_put(t_mlx *mlx, t_img *img, int x, int y)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, x, y);
}

/**
 * @brief init minilibx
 * 
 * @param mlx mlx struct
 * @return false if failed
 */
bool	ft_minilibx_init(t_mlx *mlx, t_img *img, t_img *mmap)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (false);
	mlx_get_screen_size(mlx->ptr, &img->w, &img->h);
	img->ptr = mlx_new_image(mlx->ptr, img->w, img->h);
	if (!img->ptr)
		return (false);
	if (!ft_image_init(img))
		return (false);
	mmap->w = 220;
	mmap->h = 220;
	mmap->ptr = mlx_new_image(mlx->ptr, mmap->w, mmap->h);
	if (!ft_image_init(mmap))
		return (false);
	mlx->win = mlx_new_window(mlx->ptr, img->w, img->h, "cub3d");
	if (!mlx->win)
		return (false);
	return (true);
}

/**
 * @brief free minilibx
 * 
 * @param mlx mlx struct
 */
void	ft_minilibx_free(t_mlx *mlx, t_img *img, t_img *mmap)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_image(mlx->ptr, img->ptr);
	mlx_destroy_image(mlx->ptr, mmap->ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	ft_free(mlx->ptr);
}
