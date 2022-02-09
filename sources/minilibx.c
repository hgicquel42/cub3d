/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:29:54 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 07:15:08 by vpiamias         ###   ########.fr       */
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
 * @brief init image data address
 * 
 * @param img img struct
 * @return false if failed
 */
bool	ft_image_init(t_img *i)
{
	i->data = (int *)mlx_get_data_addr(i->ptr, &i->bpp, &i->line, &i->end);
	if (!i->data)
		return (false);
	return (true);
}

/**
 * @brief put image to window
 * 
 * @param mlx mlx struct
 * @param img img struct
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
bool	ft_minilibx_init(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (false);
	mlx_get_screen_size(mlx->ptr, &mlx->img.w, &mlx->img.h);
	mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->img.w, mlx->img.h);
	if (!mlx->img.ptr)
		return (false);
	if (!ft_image_init(&mlx->img))
		return (false);
	mlx->win = mlx_new_window(mlx->ptr, mlx->img.w, mlx->img.h, "cub3d");
	if (!mlx->win)
		return (false);
	mlx_get_screen_size(mlx->ptr, &mlx->screen.x, &mlx->screen.y);
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
	mlx_destroy_image(mlx->ptr, mlx->north.ptr);
	mlx_destroy_image(mlx->ptr, mlx->south.ptr);
	mlx_destroy_image(mlx->ptr, mlx->east.ptr);
	mlx_destroy_image(mlx->ptr, mlx->west.ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	ft_free(mlx->ptr);
}
