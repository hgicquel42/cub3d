/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:23:03 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/08 14:56:21 by hgicquel         ###   ########.fr       */
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
			if ((i == 0 || i == k) && !ft_iswall(body[i][j]))
				return (false);
			if ((j == 0 || j == l) && !ft_iswall(body[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	ft_xyaw(char dir, t_dpos *vec)
{
	vec->x = 0;
	vec->y = 0;
	if (dir == 'N')
		vec->x = 1;
	else if (dir == 'S')
		vec->x = -1;
	else if (dir == 'E')
		vec->y = 1;
	else if (dir == 'W')
		vec->y = -1;
	else
		return (false);
	return (true);
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
			if (ft_xyaw(body[i][j], &player->yaw))
			{
				player->pos.x = i;
				player->pos.y = j;
				count++;
			}
			j++;
		}
		i++;
	}
	return (count == 1);
}

void	ft_body_print(char **body)
{
	while (*body)
		printf("%s\n", *body++);
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
	if (!ft_body_check_chars(body))
		return (false);
	if (!ft_body_parse_player(body, &g->player))
		return (false);
	ft_body_print(body);
	return (true);
}
