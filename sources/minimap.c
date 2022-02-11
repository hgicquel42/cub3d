/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:01:37 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/11 11:36:55 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "image.h"
#include "mlx.h"
#include "positions.h"
#include "draw.h"
#include "parsing/pchars.h"

void	ft_print_player(t_img map, t_pos pos)
{
	pos.y = 105;
	while (pos.y < 115)
	{
		pos.x = 105;
		while (pos.x < 115)
		{
			ft_draw_pixel(&map, pos.y, pos.x, 0xffffff);
			pos.x++;
		}
		pos.y++;
	}
}

void	ft_print_map(t_img map, t_pos *pos, int i, int color)
{
	int	j;
	int	k;

	(void)i;
	j = pos->y + 20;
	k = pos->x + 20;
	while (pos->y < j)
	{
		pos->x = k - 20;
		while (pos->x < k)
		{
			ft_draw_pixel(&map, pos->y, pos->x, color);
			pos->x++;
		}
		pos->y++;
	}
}

void	ft_minimap(t_global *g)
{
	t_img	map;
	t_pos	pos;
	int		i;

	pos.y = -6;
	i = 0;
	(void)i;
	map.ptr = mlx_new_image(g->mlx.ptr, 220, 220);
	map.h = 220;
	map.w = 220;
	map.data = mlx_get_data_addr(map.ptr, &map.bpp, &map.line, &map.end);
	/*while (i < 6)
	{
		if (!ft_ismap(g->map.body[(int)(g->player.pos.x + i)][(int)(g->player.pos.y + i)]))
			ft_print_map(map, &pos, i, 0x000000);
		else if (ft_iswall(g->map.body[(int)(g->player.pos.x + i)][(int)(g->player.pos.y + i)]))
			ft_print_map(map, &pos, i, 0x0000FF);
		else if (ft_isfloor(g->map.body[(int)(g->player.pos.x + i)][(int)(g->player.pos.y + i)]))
			ft_print_map(map, &pos, i, 0xFF0000);
		i++;
	}*/
	ft_print_player(map, pos);
	mlx_put_image_to_window(g->mlx.ptr, g->mlx.win, map.ptr, 20, 20);
}