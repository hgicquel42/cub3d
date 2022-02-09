/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:13:49 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 16:49:47 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "raycast.h"
#include "global.h"
#include "loop.h"

/**
 * @brief called on window close
 * 
 * @param g global
 * @return int 0
 */
static int	on_close(t_global *g)
{
	mlx_loop_end(g->mlx.ptr);
	return (0);
}

/**
 * @brief called on key press
 * 
 * @param code key code
 * @param g global
 * @return int 0
 */
static int	on_keydown(int code, t_global *g)
{
	if (code == 119)
		g->player.move.x = 1;
	else if (code == 115)
		g->player.move.x = -1;
	else if (code == 100)
		g->player.move.y = 1;
	else if (code == 97)
		g->player.move.y = -1;
	else if (code == 65361)
		g->player.rotate = 1;
	else if (code == 65363)
		g->player.rotate = -1;
	else if (code == 65307)
		on_close(g);
	return (0);
}

/**
 * @brief called on key release
 * 
 * @param code key code
 * @param g global
 * @return int 0
 */
static int	on_keyup(int code, t_global *g)
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
 * @brief called on each frame (~60Hz)
 * 
 * @param g global
 * @return int 0
 */
static int	on_loop(t_global *g)
{
	if (!ft_loop(g))
		mlx_loop_end(g->mlx.ptr);
	return (0);
}

/**
 * @brief create hooks
 * 
 * @param g global
 */
void	ft_minilibx_hook(t_global *g)
{
	mlx_hook(g->mlx.win, 2, 1L << 0, on_keydown, g);
	mlx_hook(g->mlx.win, 3, 1L << 1, on_keyup, g);
	mlx_hook(g->mlx.win, 17, 0, on_close, g);
	mlx_loop_hook(g->mlx.ptr, on_loop, g);
}
