/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:34:18 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/10 17:30:09 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBERS_H
# define NUMBERS_H

# include <stdbool.h>

/**
 * @brief safely transform string to char number
 * 
 * @param s string
 * @param r result
 * @return false if failed (overflow is fail)
 */
bool	ft_xatoc(char *s, char *r);

/**
 * @brief min of doubles
 * 
 * @param a 
 * @param b 
 * @return double 
 */
double	ft_minf(double a, double b);

/**
 * @brief max of doubles
 * 
 * @param a 
 * @param b 
 * @return double 
 */
double	ft_maxf(double a, double b);

/**
 * @brief return sign of x
 * 
 * @param x 
 * @return int 
 */
int		ft_sign(double x);

#endif
