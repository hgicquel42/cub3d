/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcolors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:13:26 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 15:50:32 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PCOLORS_H
# define PCOLORS_H

# include <stdbool.h>

/**
 * @brief parse string rgg color into rgb color array
 * 
 * @param color string "255,128,0"
 * @param result array [255,128,0]
 * @return false if failed
 */
bool			ft_color_parse(char *color, char result[3]);

#endif
