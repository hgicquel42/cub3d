/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:50:59 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 12:21:40 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include <stdlib.h>
#include "minilibx.h"

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
 * @param i x
 */
void	ft_draw_column(t_img *img, int i)
{
	int	j;

	j = 0;
	while (j < img->h)
	{
		ft_draw_pixel(img, i, j, rand());
		j++;
	}
}
