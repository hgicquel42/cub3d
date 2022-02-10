/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:07:51 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/10 19:17:06 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include "vector.h"
# include "vector2.h"

/**
 * @brief negate vector
 * 
 * @param v 
 * @return t_vec 
 */
t_vec	ft_vecneg(t_vec v);

/**
 * @brief calculate delta of ray vector
 * 
 * @param v 
 * @return t_vec 
 */
t_vec	ft_vecdelta(t_vec v);

/**
 * @brief translate vector by movement
 * 
 * @param v vector
 * @param m movement
 * @return t_vec 
 */
t_vec	ft_vecmove(t_vec v, t_vec m);

/**
 * @brief dot product of a and b
 * 
 * @param a 
 * @param b 
 * @return double 
 */
double	ft_vecdot(t_vec a, t_vec b);

/**
 * @brief print vector
 * 
 * @param v 
 */
void	ft_vecprint(t_vec v);

#endif
