/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:50:59 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 18:10:01 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include <stdlib.h>
#include "minilibx.h"
#include "raycast.h"
#include "math.h"
#include "./utils/colors.h"

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
 *
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
*/

//PROTOTYPE p
// Mettre ray / wall ou j dans g || metre j dans ray ou wall pour norme
// int		ft_get_wall_texture(t_global *g, t_ray *ray, int i, int h) // Mettre ray / wall ou i dans g pour norme
// {
// 	g->s.step = 1.0 * g->img.h / h;
// 	g->s.cord.x = (int)(g->s.x_wall * (double)g->img.w);
// 	if (ray->side == 0 && ray->yaw.x > 0)
// 		g->s.cord.x = g->img.w - g->s.cord.x - 1;
// 	if (ray->side == 0 && ray->yaw.y < 0)
// 		g->s.cord.x = g->img.w - g->s.cord.x -1;
// 	g->s.pos = (wall->start - g->img.h / 2 + wall->height / 2) * g->s.step;
// 	g->s.cord.y = floor(g->s.pos);
// 	g->s.pos += g->s.step;
// 	return ((int)img->data[g->s.cord.y * img->line / 4 + g->s.cord.x]);
// }


// Doit renvoyer le pixel de la texture correspondant a j i
// lamcer une fontion avec l'image corespondante a l'orientation

int	ft_get_wall_pixel(t_global *g, t_ray *ray, int i)
{
	(void)i;
	(void)g;
	if (ray->side == RSIDE_NORTH)
		return (0xFFFFFF);
	else if (ray->side == RSIDE_SOUTH)
		return (0x00FFFF);
	else if (ray->side == RSIDE_EAST)
		return (0xFF00FF);
	else if (ray->side == RSIDE_WEST)
		return (0xFFFF00);
	return (0);
}

/**
 * @brief draw screen column
 * 
 * @param g 
 * @param ray 
 * @param i 
 */
void	ft_draw_column(t_global *g, t_ray *ray, int i)
{
	int		j;
	int		height;
	int		start;
	int		end;

	j = 0;
	height = g->img.h / ray->dist;
	start = (g->img.h / 2) - (height / 2);
	end = (g->img.h / 2) + (height / 2);
	while (j < start && j < g->img.h)
		ft_draw_pixel(&g->img, i, j++, 0x000000);
	while (j < end && j < g->img.h)
		ft_draw_pixel(&g->img, i, j++, 0xffffff);
	while (j < g->img.h)
		ft_draw_pixel(&g->img, i, j++, 0xababab);
}
