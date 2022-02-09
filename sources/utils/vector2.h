/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:55:22 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 15:02:39 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

# include "vector.h"

/**
 * @brief normalize vector
 * 
 * @param v 
 * @return t_vec 
 */
t_vec	ft_vecnorm(t_vec v);

/**
 * @brief add vectors
 * 
 * @param a 
 * @param b 
 * @return t_vec 
 */
t_vec	ft_vecadd(t_vec a, t_vec b);

/**
 * @brief subtract vectors
 * 
 * @param a 
 * @param b 
 * @return t_vec 
 */
t_vec	ft_vecsub(t_vec a, t_vec b);

/**
 * @brief normal vector clockwise
 * 
 * @param v 
 * @return t_vec 
 */
t_vec	ft_vecperpp(t_vec v);

/**
 * @brief normal vector counter-clockwise
 * 
 * @param v 
 * @return t_vec 
 */
t_vec	ft_vecperpn(t_vec v);

#endif
