/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:19:19 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 12:39:19 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

#include "global.h"
#include "utils/vector3.h"
#include "parsing/pchars.h"

/**
 * @brief smoothly increase or decrease x value
 * 
 * @param x 
 * @return double 
 */
double	ft_smooth(double x)
{
	if (x > 0)
		return (ft_minf(0, x - 0.001));
	if (x < 0)
		return (ft_maxf(0, x + 0.001));
	return (x);
}

void	ft_move_x(t_global *g, t_player *player)
{
	double		value;
	t_vec		yaw;
	t_vec		pos;

	if (!player->move.x)
		return ;
	if (g->keys.shift)
		yaw = ft_vecmul(player->yaw, player->move.x * 0.2);
	else
		yaw = ft_vecmul(player->yaw, player->move.x * 0.1);
	pos = ft_vecadd(player->pos, yaw);
	if (ft_iswall(g->map.body[(int)pos.x][(int)pos.y]))
		return ;
	player->move.x = ft_smooth(player->move.x);
	player->pos = pos;
}

void	ft_move_y(t_global *g, t_player *player)
{
	double		value;
	t_vec		yaw;
	t_vec		pos;

	if (!player->move.y)
		return ;
	if (g->keys.shift)
		yaw = ft_vecmul(player->yaw, player->move.y * 0.2);
	else
		yaw = ft_vecmul(player->yaw, player->move.y * 0.1);
	yaw = ft_vecperpp(yaw);
	pos = ft_vecadd(player->pos, yaw);
	if (ft_iswall(g->map.body[(int)pos.x][(int)pos.y]))
		return ;
	player->move.y = ft_smooth(player->move.y);
	player->pos = pos;
}

void	ft_rotate(t_global *g, t_player *player)
{
	t_vec	old;
	double	val;

	if (!player->rotate)
		return ;
	old = g->player.yaw;
	val = g->player.rotate * 0.1;
	g->player.yaw.x = old.x * cos(val) - old.y * sin(val);
	g->player.yaw.y = old.x * sin(val) + old.y * cos(val);
	g->player.rotate = ft_smooth(g->player.rotate);
}

void	ft_move(t_global *g)
{
	t_player	*player;

	player = &g->player;
	ft_move_x(g, player);
	ft_move_y(g, player);
	ft_rotate(g, player);
}
