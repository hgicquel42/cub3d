/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pheader.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:02:48 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/15 12:22:31 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pheader.h"

#include <stdlib.h>
#include "utils/chars.h"
#include "utils/pointers.h"
#include "utils/strings.h"
#include "utils/strings2.h"
#include "utils/split.h"
#include "parsing/pcolors.h"

static bool	ft_header_fill(char *key, char *value, t_header *header)
{
	if (!ft_strcmp(key, "NO"))
		header->north = ft_strdup(value);
	else if (!ft_strcmp(key, "SO"))
		header->south = ft_strdup(value);
	else if (!ft_strcmp(key, "EA"))
		header->east = ft_strdup(value);
	else if (!ft_strcmp(key, "WE"))
		header->west = ft_strdup(value);
	else if (!ft_strcmp(key, "F"))
		header->rfloor = ft_strdup(value);
	else if (!ft_strcmp(key, "C"))
		header->rcell = ft_strdup(value);
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
	if (!header->rcell || !header->rfloor)
		return (false);
	return (true);
}

/**
 * @brief parse map header
 * 
 * @param lines map lines
 * @return bool	false if failed 
 */
bool	ft_header_parse(t_global *g, char **lines, t_header *header)
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
		ft_freep((void **) kv);
		i++;
	}
	if (!lines[i])
		return (false);
	if (!ft_color_parse(header->rfloor, header->floor))
		return (false);
	if (!ft_color_parse(header->rcell, header->cell))
		return (false);
	g->map.body = g->map.lines + i;
	return (true);
}

int	ft_header_size2(char *array, int i)
{
	while (array[i] != '\n')
		i++;
	return (i);
}

/**
 * @brief Return i at start of body
 * 
 * @param array 
 * @return int 
 */
int	ft_header_size(char *array)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (array[i])
	{
		if (array[i] == 'N' && array[i + 1] == 'O')
			count++;
		if (array[i] == 'S' && array[i + 1] == 'O')
			count++;
		if (array[i] == 'W' && array[i + 1] == 'E')
			count++;
		if (array[i] == 'E' && array[i + 1] == 'A')
			count++;
		if (array[i] == 'C')
			count++;
		if (array[i] == 'F')
			count++;
		if (count == 6)
			return (ft_header_size2(array, i));
		i++;
	}
	return (-1);
}
