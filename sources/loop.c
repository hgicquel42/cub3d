/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:44:09 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 12:29:19 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "draw.h"

bool	ft_loop_draw(t_global *g)
{
	int		i;
	t_ray	ray;

	ft_ray_init(&ray, &g->player);
	i = 0;
	while (i < g->img.w)
	{
		ft_ray_reinit(&ray, &g->player, i, g->img.w);
		ft_draw_column(&g->img, i);
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
