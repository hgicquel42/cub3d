/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:13:49 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 19:57:04 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "raycast.h"
#include "global.h"

int	on_close(t_global *g)
{
	mlx_loop_end(g->mlx.ptr);
	return (0);
}

int	on_key(int code, t_global *g)
{
	(void) code;
	(void) g;
	return (0);
}

unsigned int	*ft_image_addr(t_img *img, int i)
{
	return ((unsigned int *) &img->data[i]);
}

void	ft_image_set(t_mlx *mlx, int x, int y, int color)
{
	*ft_image_addr(&mlx->img, (y * mlx->img.line) + (x * 4)) = color;
}

int	on_loop(t_global *g)
{
	int		i;
	int		j;

	i = 0;
	while (i < g->mlx.img.w)
	{
		j = 0;
		while (j < g->mlx.img.h)
		{
			ft_image_set(&g->mlx, i, j, rand());
			j++;
		}
		i++;
	}
	ft_image_put(&g->mlx, &g->mlx.img);
	return (0);
}

/**
 * @brief create hooks
 * 
 * @param g global
 */
void	ft_minilibx_hook(t_global *g)
{
	mlx_loop_hook(g->mlx.ptr, on_loop, g);
	mlx_key_hook(g->mlx.win, on_key, g);
	mlx_hook(g->mlx.win, 17, 0, on_close, g);
}
