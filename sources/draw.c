/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:50:59 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/11 11:01:06 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

#include <stdlib.h>
#include "minilibx.h"
#include "raycast.h"
#include "math.h"
#include "./utils/colors.h"
#include "wall.h"
#include <stdio.h>

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
int		ft_get_wall_texture(t_global *g, t_ray *ray, t_img *img, int i, int j, t_wall *wall) // Mettre ray / wall ou i dans g pour norme
{
	unsigned int	*t;
	unsigned int	*d;
	
	// printf("start = %d\n", wall->start);
	t = ft_image_addr(img, 0);
	d = ft_image_addr(&g->img, 0);
	// printf("x_wall = %f\n", g->s.x_wall);
	// printf("img->w = %d\n", img->w);
	g->s.cord.x = (int)(g->s.x_wall * (double)img->w);
	if (ray->side == 0 && ray->yaw.x > 0)
		g->s.cord.x = img->w - g->s.cord.x -1;
	if (ray->side == 0 && ray->yaw.y < 0)
		g->s.cord.x = img->w - g->s.cord.x -1;
	// printf("X = %d\n", g->s.cord.x);
	// printf("img->h = %d wall->h = %d\n", img->h, wall->h);
	g->s.step = 1.0 * img->h / wall->h;
	g->s.pos = (wall->start - g->img.h / 2 + wall->h / 2) * g->s.step;
	// printf("step = %f, pos = %f\n", g->s.step, g->s.pos);
	// exit (0);
	// printf("j = %d wall->start = %d\n", j, wall->start);
	while (j < wall->end)
	{
		g->s.cord.y = floor(g->s.pos);
		g->s.pos += g->s.step;
		if (j < g->img.h && i < g->img.w)
		{
			d[j * g->img.line / 4 + i] = t[g->s.cord.y * img->line / 4 + g->s.cord.x];
		}
		j++;
	}
	return (0);
}


// Doit renvoyer le pixel de la texture correspondant a j i
// lamcer une fontion avec l'image corespondante a l'orientation

int	ft_get_wall_pixel(t_global *g, t_ray *ray, int i, int j, t_wall *wall)
{
	// printf("dist = %f\n", ray->dist);
	// printf("P_X = %f P_Y = %f Y_X = %f Y_Y = %f\n", ray->pos.x, ray->pos.y, ray->yaw.x, ray->yaw.y);
	if (ray->side == RSIDE_NORTH || ray->side == RSIDE_SOUTH)
		g->s.x_wall = ray->pos.y + ray->dist * ray->yaw.y;
	else
		g->s.x_wall = ray->pos.x + ray->dist * ray->yaw.x;
	g->s.x_wall -= floor(g->s.x_wall);
	// printf("x_wall = %f\n", g->s.x_wall);
	if (ray->side == RSIDE_NORTH)
		return (ft_get_wall_texture(g, ray, &g->xpms.north, i, j, wall));
	else if (ray->side == RSIDE_SOUTH)
		return (ft_get_wall_texture(g, ray, &g->xpms.south, i, j, wall));
	else if (ray->side == RSIDE_EAST)
		return (ft_get_wall_texture(g, ray, &g->xpms.east, i, j, wall));
	else if (ray->side == RSIDE_WEST)
		return (ft_get_wall_texture(g, ray, &g->xpms.west, i, j, wall));
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
	t_wall	wall;

	j = 0;
	// printf("Y = %d dist = %f\n", g->img.h, ray->dist);
	wall.h = g->img.h / ray->dist;
	wall.start = (g->img.h / 2) - (wall.h / 2);
	wall.end = (g->img.h / 2) + (wall.h / 2);
	while (j < wall.start)
		ft_draw_pixel(&g->img, i, j++, ft_rgbtohex(g->map.header.floor));
	// while (j < end && j < g->img.h)
		// ft_draw_pixel(&g->img, i, j++, ft_get_wall_pixel(g, ray, i, j));
	ft_get_wall_pixel(g, ray, i, j, &wall);
	j = wall.end;
	while (j < g->img.h)
		ft_draw_pixel(&g->img, i, j++, ft_rgbtohex(g->map.header.cell));
}
