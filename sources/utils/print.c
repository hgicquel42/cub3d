/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:41:15 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/04 14:11:38 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief write string in fd
 * 
 * @param fd file
 * @param s string
 * @return int bytes written or -1 if error
 */
int	ft_putfd(int fd, char *s)
{
	return (write(fd, s, ft_strlen(s)));
}

/**
 * @brief write string in stdout
 * 
 * @param s string
 * @return int bytes written or -1 if error
 */
int	ft_putout(char *s)
{
	return (ft_putfd(1, s));
}

/**
 * @brief write string in stderr
 * 
 * @param s string
 * @return int bytes written or -1 if error
 */
int	ft_puterr(char *s)
{
	return (ft_putfd(2, s));
}
