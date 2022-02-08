/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:00:16 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 15:50:11 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

/**
 * @brief init color array
 * 
 * @param color array
 */
void	ft_color_init(char color[3]);

/**
 * @brief convert rgb array to hex
 * 
 * @param color 
 * @return hex value
 */
unsigned long	ft_rgbtohex(char color[3]);

#endif
