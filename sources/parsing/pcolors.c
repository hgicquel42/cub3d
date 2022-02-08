/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcolors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:07:14 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 15:50:26 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pcolors.h"

#include "utils/numbers.h"
#include "utils/pointers.h"
#include "utils/split.h"

static bool	ft_iscomma(char c)
{
	return (c == ',');
}

/**
 * @brief parse subcolor into char
 * 
 * @param s subcolor "255"
 * @param r char value 255
 * @return false if failed
 */
static bool	ft_color_parse_sub(char *s, char *r)
{
	int	x;

	if (!ft_xatoi(s, &x))
		return (false);
	if (x < 0 || x > 255)
		return (false);
	*r = x;
	return (true);
}

/**
 * @brief parse string rgg color into rgb color array
 * 
 * @param color string "255,128,0"
 * @param result array [255,128,0]
 * @return false if failed
 */
bool	ft_color_parse(char *color, char result[3])
{
	char	**rgb;

	rgb = ft_split(color, ft_iscomma);
	if (!rgb)
		return (false);
	if (ft_ptrlen((void **) rgb) != 3)
		return (false + ft_freep((void **) rgb));
	if (!ft_color_parse_sub(rgb[0], &result[0]))
		return (false + ft_freep((void **) rgb));
	if (!ft_color_parse_sub(rgb[1], &result[1]))
		return (false + ft_freep((void **) rgb));
	if (!ft_color_parse_sub(rgb[2], &result[2]))
		return (false + ft_freep((void **) rgb));
	ft_freep((void **) rgb);
	return (true);
}
