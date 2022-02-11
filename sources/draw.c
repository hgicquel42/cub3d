/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:50:59 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/11 14:58:42 by hgicquel         ###   ########.fr       */
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

/**
 * @brief get pixel at (x y)
 * 
 * @param img 
 * @param x 
 * @param y 
 * @return unsigned int* 
 */
unsigned int	*ft_pixel(t_img *img, int x, int y)
{
	int				pos;

	pos = ((img->h - y - 1) * img->line) + (x * 4);
	return ((unsigned int *) &img->data[pos]);
}

static t_img	*ft_get_xpm(t_ray *ray, t_xpms *xpms)
{
	if (ray->side == RSIDE_NORTH)
		return (&xpms->north);
	else if (ray->side == RSIDE_SOUTH)
		return (&xpms->south);
	else if (ray->side == RSIDE_EAST)
		return (&xpms->east);
	else
		return (&xpms->west);
}

static int	ft_draw_wall(t_global *g, t_ray *r, t_wall *w, int j)
{
	unsigned int	color;
	double			step;
	double			curr;
	t_pos			cords;

	cords.x = (int)(w->x * (double)w->t->w);
	cords.y = 0;
	if (r->side == RSIDE_SOUTH || r->side == RSIDE_WEST)
		cords.x = w->t->w - cords.x - 1;
	step = 1.0 * w->t->h / w->h;
	curr = (w->b - (g->img.h / 2) + (w->h / 2)) * step;
	while (j < w->e && j < g->img.h)
	{
		cords.y = (int) curr & (w->t->h - 1);
		color = *ft_pixel(w->t, cords.x, cords.y);
		*ft_pixel(&g->img, w->i, j) = color;
		curr += step;
		j++;
	}
	return (j);
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
	t_img	*t;
	t_wall	w;

	j = 0;
	t = ft_get_xpm(ray, &g->xpms);
	w = ft_wall(ray, &g->img, t, i);
	while (j < w.b && j < g->img.h)
		*ft_pixel(&g->img, i, j++) = ft_rgbtohex(g->map.header.floor);
	j = ft_draw_wall(g, ray, &w, j);
	while (j < g->img.h)
		*ft_pixel(&g->img, i, j++) = ft_rgbtohex(g->map.header.cell);
}
