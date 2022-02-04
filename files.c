/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:11:50 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/04 08:07:55 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * @brief safely count length of file
 * 
 * @param file
 * @param result
 * @return bool false if it failed
 */
int	ft_seek(int file, int *result)
{
	char	buffer[1024];
	int		bytes;
	int		total;

	total = 0;
	while (1)
	{
		bytes = read(file, buffer, 1024);
		if (bytes == -1)
			return (-1);
		if (bytes == 0)
			break ;
		total += bytes;
	}
	*result = total;
	return (0);
}

/**
 * @brief safely read file
 * 
 * @param filename
 * @param result
 * @return bool false if it failed 
 */
int	ft_read(char *filename, char **result)
{
	int		file;
	int		length;
	char	*array;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (-1);
	if (ft_seek(file, &length) < 0)
		return (-1);
	close(file);
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (-1);
	array = malloc(length + 1);
	if (!array)
		return (-1);
	if (read(file, array, length) != length)
		return (-1);
	array[length] = 0;
	*result = array;
	return (0);
}
