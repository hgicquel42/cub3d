/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbody.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:23:03 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/11 12:05:36 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pbody.h"

#include "utils/pointers.h"
#include "utils/strings.h"
#include "utils/vector3.h"
#include "pchars.h"

static bool	ft_body_check_line(char **body, int i, int k)
{
	int	j;
	int	l;

	j = 0;
	l = ft_strlen(body[i]) - 1;
	(void)l;
	(void)k;
	while (body[i][j])
	{
		if (!ft_ismap(body[i][j]))
			return (false);
		if (!ft_iswall(body[i][j]))
		{
			if (i == 0 || i == k || j == 0 || j == l)
				return (false);
			if (j > ft_strlen(body[i - 1]) - 1)
				return (false);
			if (j > ft_strlen(body[i + 1]) - 1)
				return (false);
		}
		j++;
	}
	return (true);
}

static bool	ft_body_check_lines(char **body)
{
	int	i;
	int	k;

	i = 0;
	k = ft_ptrlen((void **) body) - 1;
	while (body[i])
		if (!ft_body_check_line(body, i++, k))
			return (false);
	return (true);
}

static void	ft_xyaw(char dir, t_vec *vec)
{
	vec->x = 0;
	vec->y = 0;
	if (dir == 'N')
		vec->x = -1;
	else if (dir == 'S')
		vec->x = 1;
	else if (dir == 'E')
		vec->y = -1;
	else if (dir == 'W')
		vec->y = 1;
}

static bool	ft_body_parse_player(char **body, t_player *player)
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
			{
				ft_xyaw(body[i][j], &player->yaw);
				player->pos.x = i + 0.5;
				player->pos.y = j + 0.5;
				body[i][j] = '0';
				count++;
			}
			j++;
		}
		i++;
	}
	return (count == 1);
}

/**
 * @brief parse map body
 * 
 * @param g 
 * @return true 
 * @return false 
 */
bool	ft_body_parse(t_global *g, char **body)
{
	if (!ft_body_check_lines(body))
		return (false);
	if (!ft_body_parse_player(body, &g->player))
		return (false);
	return (true);
}
