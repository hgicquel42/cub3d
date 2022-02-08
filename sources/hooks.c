/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:13:49 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 17:39:44 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

#include "../minilibx/mlx.h"
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

int	on_loop(t_global *g)
{
	(void) g;
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
