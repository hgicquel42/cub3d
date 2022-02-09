/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:13:49 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 04:25:09 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "raycast.h"
#include "global.h"
#include "stdio.h"

int	on_close(t_global *g)
{
	mlx_loop_end(g->mlx.ptr);
	return (0);
}

int	on_key(int code, t_global *g)
{
	if (code == 119)
		g->player.move.x = 1;
	if (code == 115)
		g->player.move.x = -1;
	if (code == 100)
		g->player.move.y = 1;
	if (code == 97)
		g->player.move.y = -1;
	if (code == 65361)
		g->player.rotate = 1;
	if (code == 65363)
		g->player.rotate = -1;
	if (code == 65307)
		on_close(g);
	return (0);
}

int	key_release(int code, t_global *g)
{
	if (code == 119)
		g->player.move.x = 0;
	if (code == 115)
		g->player.move.x = 0;
	if (code == 97)
		g->player.move.y = 0;
	if (code == 100)
		g->player.move.y = 0;
	if (code == 65361)
		g->player.rotate = 0;
	if (code == 65363)
		g->player.rotate = 0;
	return (0);
}

/**
 * @brief create hooks
 * 
 * @param g global
 */
void	ft_minilibx_hook(t_global *g)
{
	mlx_hook(g->mlx.win, 2, 1L << 0, on_key, g);
	mlx_hook(g->mlx.win, 17, 0, on_close, g);
	mlx_loop_hook(g->mlx.ptr, ft_ray_cast, g);
	mlx_hook(g->mlx.win, 3, 1L << 1, key_release, g);
}
