/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:41:15 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/04 08:43:05 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include <unistd.h>

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
 * @brief write string in stderr
 * 
 * @param s string
 * @return int bytes written or -1 if error
 */
int	ft_puterr(char *s)
{
	return (ft_putfd(2, s));
}
