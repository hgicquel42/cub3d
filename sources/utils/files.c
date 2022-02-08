/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:11:50 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 16:28:59 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "utils/pointers.h"

/**
 * @brief safely count length of file
 * 
 * @param file
 * @param result
 * @return bool false if it failed
 */
bool	ft_seek(int file, int *result)
{
	char	buffer[1024];
	int		bytes;
	int		total;

	total = 0;
	while (true)
	{
		bytes = read(file, buffer, 1024);
		if (bytes == -1)
			return (false);
		if (bytes == 0)
			break ;
		total += bytes;
	}
	*result = total;
	return (true);
}

/**
 * @brief safely read file
 * 
 * @param filename
 * @param result
 * @return bool false if it failed 
 */
bool	ft_read(char *path, char **result)
{
	int		file;
	int		length;
	char	*array;

	file = open(path, O_RDONLY);
	if (file == -1)
		return (false);
	if (!ft_seek(file, &length))
		return (false);
	close(file);
	file = open(path, O_RDONLY);
	if (file == -1)
		return (false);
	array = malloc(length + 1);
	if (!array)
		return (false);
	if (read(file, array, length) != length)
		return (false + ft_free(array));
	array[length] = 0;
	*result = array;
	return (true);
}
