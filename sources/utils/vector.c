/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:49:50 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 14:57:49 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include <math.h>

/**
 * @brief create vector
 * 
 * @param x 
 * @param y 
 * @return t_vec 
 */
t_vec	ft_vec(double x, double y)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	return (v);
}

/**
 * @brief zero vector
 * 
 * @return t_vec 
 */
t_vec	ft_veczero(void)
{
	return (ft_vec(0, 0));
}

/**
 * @brief vector length
 * 
 * @param v 
 * @return double 
 */
double	ft_veclen(t_vec v)
{
	return (sqrt(powf(v.x, 2) + powf(v.y, 2)));
}

/**
 * @brief multiply vector
 * 
 * @param v 
 * @param l 
 * @return t_vec 
 */
t_vec	ft_vecmul(t_vec v, double l)
{
	return (ft_vec(v.x * l, v.y * l));
}

/**
 * @brief divide vector
 * 
 * @param v 
 * @param l 
 * @return t_vec 
 */
t_vec	ft_vecdiv(t_vec v, double l)
{
	return (ft_vec(v.x / l, v.y / l));
}
