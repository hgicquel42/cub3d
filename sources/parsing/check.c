/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:23:03 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 18:19:38 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	ft_body_check_chars(char **body)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = ft_ptrlen((void **) body) - 1;
	while (body[i])
	{
		j = 0;
		l = ft_strlen(body[i]) - 1;
		while (body[i][j])
		{
			if (!ft_ismap(body[i][j]))
				return (false);
			if ((i == 0 || i == k) && body[i][j] != '1')
				return (false);
			if ((j == 0 || j == l) && body[i][j] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	ft_body_check_player(char **body)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (body[i])
	{
		j = 0;
		while (body[i][j])
		{
			if (ft_isplayer(body[i][j]))
				count++;
			j++;
		}
		i++;
	}
	return (count == 1);
}

static void	ft_body_close_border(char **body)
{
	int	i;
	int	j;

	i = 0;
	while (body[i])
	{
		j = 0;
		while (body[i][j])
		{
			if (ft_isblank(body[i][j]))
				body[i][j] = '1';
			j++;
		}
		i++;
	}
}

/**
 * @brief check map
 * 
 * @param g 
 * @return true 
 * @return false 
 */
bool	ft_map_check(t_global *g)
{
	if (!ft_color_check(g->map.header.floor))
		return (false);
	if (!ft_color_check(g->map.header.cell))
		return (false);
	ft_body_close_border(g->map.body);
	if (!ft_body_check_chars(g->map.body))
		return (false);
	if (!ft_body_check_player(g->map.body))
		return (false);
	return (true);
}
