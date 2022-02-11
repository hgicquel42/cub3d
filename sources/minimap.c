/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:01:37 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/11 15:32:09 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "image.h"
#include "mlx.h"
#include "positions.h"
#include "draw.h"
#include "parsing/pchars.h"
#include "utils/strings.h"
#include "utils/strings2.h"
#include "utils/colors.h"

/**
 * @brief Print player on minimap
 * 
 * @param map 
 * @param pos 
 */
void	ft_print_player(t_img *map, t_pos pos)
{
	pos.y = 105;
	while (pos.y < 115)
	{
		pos.x = 105;
		while (pos.x < 115)
		{
			*ft_pixel(map, pos.x, pos.y) = 0xffffff;
			pos.x++;
		}
		pos.y++;
	}
}

/**
 * @brief Print one case of minimap
 * 
 * @param map 
 * @param pos 
 * @param color 
 */
void	ft_print_case(t_img *map, t_pos pos, int color)
{
	int	j;
	int	k;

	j = pos.y + 20;
	k = pos.x + 20;
	while (pos.x < k)
	{
		pos.y = j - 20;
		while (pos.y < j)
		{
			*ft_pixel(map, pos.x, pos.y) = color;
			pos.y++;
		}
		pos.x++;
	}
}

/**
 * @brief Check if map can be display
 * 
 * @param g 
 * @param i 
 * @param j 
 * @return true 
 * @return false 
 */
bool	ft_check_map(t_global *g, int i, int j)
{
	int	x;
	int	y;	

	x = (int)g->player.pos.x;
	y = (int)g->player.pos.y;
	if ((x + i) < 0 || (y + j) < 0)
		return (false);
	else if (x + i > (ft_maplen(g->map.body) - 1)
		|| y + j > (ft_strlen(g->map.body[(x + i)]) - 1))
		return (false);
	return (true);
}

/**
 * @brief print mini_map on screen
 * 
 * @param g 
 * @param map 
 * @param pos 
 * @param play 
 */
void	ft_print_map(t_global *g, t_img *map, t_pos pos, t_pos play)
{
	int	i;
	int	j;

	i = -5;
	while (i < 6)
	{
		j = -5;
		pos.y = 0;
		while (j < 6)
		{
			if (!ft_check_map(g, i, j))
				ft_print_case(map, pos, ft_rgbtohex(g->map.header.cell));
			else if (ft_iswall(g->map.body[play.x + i][play.y + j]))
				ft_print_case(map, pos, 0xffffff);
			else
				ft_print_case(map, pos, ft_rgbtohex(g->map.header.floor));
			pos.y += 20;
			j++;
		}
		pos.x += 20;
		i++;
	}
}

/**
 * @brief manage minimap
 * 
 * @param g 
 */
void	ft_loop_minimap(t_global *g)
{
	t_pos	pos;
	t_pos	play;

	pos.y = 0;
	pos.x = 0;
	play.x = (int)g->player.pos.x;
	play.y = (int)g->player.pos.y;
	ft_print_map(g, &g->mmap, pos, play);
	ft_print_player(&g->mmap, pos);
}
