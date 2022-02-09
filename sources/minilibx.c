/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:29:54 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 12:18:23 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx.h"

#include <stdbool.h>
#include <stdio.h>
#include "../minilibx/mlx.h"
#include "utils/pointers.h"
#include "header.h"
#include "global.h"

/**
 * @brief put image to window
 * 
 * @param mlx mlx
 * @param img img
 */
void	ft_image_put(t_mlx *mlx, t_img *img)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
}

/**
 * @brief init minilibx
 * 
 * @param mlx mlx struct
 * @return false if failed
 */
bool	ft_minilibx_init(t_mlx *mlx, t_img *img)
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
void	ft_minilibx_free(t_mlx *mlx, t_img *img)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_image(mlx->ptr, img->ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	ft_free(mlx->ptr);
}
