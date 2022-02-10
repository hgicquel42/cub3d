/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:13:49 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 10:00:56 by vpiamias         ###   ########.fr       */
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
		g->keys.w = true;
	else if (code == 115)
		g->keys.s = true;
	else if (code == 97)
		g->keys.a = true;
	else if (code == 100)
		g->keys.d = true;
	else if (code == 65361)
		g->keys.al = true;
	else if (code == 65363)
		g->keys.ar = true;
	else if (code == 65505)
		g->keys.shift = true;
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
		g->keys.w = false;
	else if (code == 115)
		g->keys.s = false;
	else if (code == 97)
		g->keys.a = false;
	else if (code == 100)
		g->keys.d = false;
	else if (code == 65361)
		g->keys.al = false;
	else if (code == 65363)
		g->keys.ar = false;
	else if (code == 65505)
		g->keys.shift = false;
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
