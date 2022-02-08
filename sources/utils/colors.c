/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:00:09 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 15:50:03 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

/**
 * @brief init color array
 * 
 * @param color array
 */
void	ft_color_init(char color[3])
{
	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
}

/**
 * @brief convert rgb array to hex
 * 
 * @param color 
 * @return hex value
 */
unsigned long	ft_rgbtohex(char color[3])
{
	unsigned long	hex;

	hex = (color[0] & 0xff) << 16;
	hex += (color[1] & 0xff) << 8;
	hex += (color[2] & 0xff);
	return (hex);
}
