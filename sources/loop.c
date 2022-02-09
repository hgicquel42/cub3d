/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:44:09 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 13:00:08 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "draw.h"
#include "raycast2.h"

bool	ft_loop_draw(t_global *g)
{
	int		i;
	double	o;
	t_ray	ray;

	ft_ray_init(&ray, &g->player);
	i = 0;
	while (i < g->img.w)
	{
		o = 2 * i / (double) g->img.w - 1;
		ft_ray_reinit(&ray, &g->player, o);
		ft_ray_launch(g, &ray);
		ft_draw_column(&g->img, &ray, i);
		i++;
	}
	return (true);
}

/**
 * @brief frame loop (60Hz)
 * 
 * @param g global
 * @return false if failed
 */
bool	ft_loop(t_global *g)
{
	if (!ft_loop_draw(g))
		return (false);
	ft_image_put(&g->mlx, &g->img);
	return (true);
}
