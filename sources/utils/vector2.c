/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:55:15 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 14:38:15 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"

#include "vector.h"

/**
 * @brief normalize vector
 * 
 * @param v 
 * @return t_vec 
 */
t_vec	ft_vecnorm(t_vec v)
{
	double	l;

	l = ft_veclen(v);
	if (!l)
		return (ft_veczero());
	return (ft_vecdiv(v, l));
}

/**
 * @brief add vectors
 * 
 * @param a 
 * @param b 
 * @return t_vec 
 */
t_vec	ft_vecadd(t_vec a, t_vec b)
{
	return (ft_vec(a.x + b.x, a.y + b.y));
}

/**
 * @brief subtract vectors
 * 
 * @param a 
 * @param b 
 * @return t_vec 
 */
t_vec	ft_vecsub(t_vec a, t_vec b)
{
	return (ft_vec(a.x - b.x, a.y - b.y));
}

/**
 * @brief normal vector clockwise
 * 
 * @param v 
 * @return t_vec 
 */
t_vec	ft_vecperpp(t_vec v)
{
	return (ft_vec(-v.y, v.x));
}

/**
 * @brief normal vector counter-clockwise
 * 
 * @param v 
 * @return t_vec 
 */
t_vec	ft_vecperpn(t_vec v)
{
	return (ft_vec(v.y, -v.x));
}
