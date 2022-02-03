/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:02:48 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 19:08:26 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**
 * @brief parse map headers
 * 
 * @param lines 
 * @return int 
 */
int	ft_header(char **lines)
{
	t_header	header;
	char		*line;
	char		**kv;
	int			i;

	i = 0;
	while (lines[i])
	{
		line = lines[i];
		while (ft_isblank(line))
			line++;
		// split by tab?
		kv = ft_split(line, ' ');
		if (!ft_strcmp(kv[0], "NO"))
			header.north = kv[1];
		else if (!ft_strcmp(kv[0], "SO"))
			header.south = kv[1];
		else if (!ft_strcmp(kv[0], "EA"))
			header.east = kv[1];
		else if (!ft_strcmp(kv[0], "WE"))
			header.west = kv[1];
		else if (!ft_strcmp(kv[0], "F"))
			header.floor = kv[1];
		else if (!ft_strcmp(kv[0], "C"))
			header.cell = kv[1];
		// TODO: free kv
		// TODO: return header + length + error
		i++;
	}
	return (-1);
}
