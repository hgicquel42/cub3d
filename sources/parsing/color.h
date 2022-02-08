/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:13:26 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 13:31:18 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "cub3d.h"

typedef char	t_rgb[3];

/**
 * @brief init color array
 * 
 * @param color array
 */
void	ft_color_init(char color[3]);

/**
 * @brief parse string rgg color into rgb color array
 * 
 * @param color string "255,128,0"
 * @param result array [255,128,0]
 * @return false if failed
 */
bool	ft_color_parse(char *color, char result[3]);

#endif
