/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pchars.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:39:16 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/04 18:12:40 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief check if c is a floor
 * 
 * @param c char
 * @return true 
 * @return false 
 */
bool	ft_isfloor(char c)
{
	return (c == '0');
}

/**
 * @brief check if c is a wall
 * 
 * @param c char
 * @return true 
 * @return false 
 */
bool	ft_iswall(char c)
{
	return (c == '1');
}

/**
 * @brief check if c is player char
 * 
 * @param c char
 * @return true 
 * @return false 
 */
bool	ft_isplayer(char c)
{
	if (c == 'N' || c == 'S')
		return (true);
	if (c == 'E' || c == 'W')
		return (true);
	return (false);
}

/**
 * @brief check if c is map char
 * 
 * @param c char
 * @return true 
 * @return false 
 */
bool	ft_ismap(char c)
{
	return (ft_iswall(c) || ft_isfloor(c) || ft_isplayer(c));
}
