/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:07:14 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/04 18:18:31 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	ft_iscomma(char c)
{
	return (c == ',');
}

static bool	ft_color_check_value(char *s)
{
	int	x;

	if (!ft_xatoi(s, &x))
		return (false);
	if (x < 0 || x > 255)
		return (false);
	return (true);
}

/**
 * @brief check color rgb values
 * 
 * @param color 
 * @return bool false if failed 
 */
bool	ft_color_check(char *color)
{
	char	**rgb;

	rgb = ft_split(color, ft_iscomma);
	if (!rgb)
		return (false);
	if (ft_ptrlen((void **) rgb) != 3)
		return (false + ft_freep((void **) rgb));
	if (!ft_color_check_value(rgb[0]))
		return (false + ft_freep((void **) rgb));
	if (!ft_color_check_value(rgb[1]))
		return (false + ft_freep((void **) rgb));
	if (!ft_color_check_value(rgb[2]))
		return (false + ft_freep((void **) rgb));
	ft_freep((void **) rgb);
	return (true);
}
