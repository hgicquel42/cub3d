/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:11:50 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 16:20:01 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

/**
 * @brief safely count length of file
 * 
 * @param fd file
 * @param r result
 * @return bool false if it failed
 */
bool	ft_seek(int fd, int *r)
{
	char	buffer[1024];
	int		bytes;
	int		total;

	while (true)
	{
		bytes = read(fd, buffer, 1024);
		if (bytes == -1)
			return (false);
		if (bytes == 0)
			break ;
		total += bytes;
	}
	*r = total;
	return (true);
}
