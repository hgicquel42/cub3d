/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:02:48 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/04 15:22:37 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief init header
 * 
 * @param header 
 */
void	ft_header_init(t_header *header)
{
	header->north = NULL;
	header->south = NULL;
	header->east = NULL;
	header->west = NULL;
	header->cell = NULL;
	header->floor = NULL;
	header->length = 0;
}

/**
 * @brief free header
 * 
 * @param header 
 * @return int 0
 */
int	ft_header_free(t_header *header)
{
	ft_free(header->north);
	ft_free(header->south);
	ft_free(header->east);
	ft_free(header->west);
	ft_free(header->cell);
	ft_free(header->floor);
	return (0);
}

static bool	ft_header_fill(char *key, char *value, t_header *header)
{
	if (!ft_strcmp(key, "NO"))
		header->north = value;
	else if (!ft_strcmp(key, "SO"))
		header->south = value;
	else if (!ft_strcmp(key, "EA"))
		header->east = value;
	else if (!ft_strcmp(key, "WE"))
		header->west = value;
	else if (!ft_strcmp(key, "F"))
		header->floor = value;
	else if (!ft_strcmp(key, "C"))
		header->cell = value;
	else
		return (false);
	return (true);
}

static bool	ft_header_full(t_header *header)
{
	if (!header->north || !header->south)
		return (false);
	if (!header->east || !header->west)
		return (false);
	if (!header->cell || !header->floor)
		return (false);
	return (true);
}

/**
 * @brief parse map header
 * 
 * @param lines map lines
 * @return bool	false if failed 
 */
bool	ft_header(char **lines, t_header *header)
{
	char		**kv;
	int			i;

	i = 0;
	while (lines[i] && !ft_header_full(header))
	{
		kv = ft_split(lines[i], ft_isblank);
		if (!kv)
			return (false);
		if (ft_ptrlen((void **) kv) != 2)
			return (false + ft_freep((void **) kv));
		if (!ft_header_fill(kv[0], kv[1], header))
			return (false + ft_freep((void **) kv));
		ft_freelp((void **) kv, 1);
		i++;
	}
	if (!lines[i])
		return (false);
	header->length = i;
	return (true);
}
