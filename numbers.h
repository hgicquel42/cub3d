/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:34:18 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 14:11:11 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBERS_H
# define NUMBERS_H

# include "cub3d.h"

int		ft_atoi(char *str);

/**
 * @brief safe version of ft_atoi
 * 
 * @param s string
 * @param r result
 * @return bool false if it failed
 */
bool	ft_xatoi(char *s, int *r);

#endif
