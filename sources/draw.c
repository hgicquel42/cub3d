/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:50:59 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 19:10:48 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include <stdlib.h>
#include "minilibx.h"
#include "raycast.h"

static unsigned int	*ft_image_addr(t_img *img, int i)
{
	return ((unsigned int *) &img->data[i]);
}

/**
 * @brief draw single pixel
 * 
 * @param img img struct
 * @param x pixel x
 * @param y pixel y
 * @param color pixel color
 */
void	ft_draw_pixel(t_img *img, int x, int y, int color)
{
	*ft_image_addr(img, (y * img->line) + (x * 4)) = color;
}

/**
 * @brief draw column
 * 
 * @param img 
 * @param ray 
 * @param i 
 */
void	ft_draw_column(t_img *img, t_wall *wall, int i)
{
	int	j;

	j = 0;
	while (j < wall->start && j < img->h)
		ft_draw_pixel(img, i, j++, 0xffffff);
	while (j < wall->end && j < img->h)
		ft_draw_pixel(img, i, j++, 0xababab);
	while (j < img->h)
		ft_draw_pixel(img, i, j++, 0x000000);
}
