/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:49:53 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 15:02:14 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

/**
 * @brief create vector
 * 
 * @param x 
 * @param y 
 * @return t_vec 
 */
t_vec	ft_vec(double x, double y);

/**
 * @brief zero vector
 * 
 * @return t_vec 
 */
t_vec	ft_veczero(void);

/**
 * @brief vector length
 * 
 * @param v 
 * @return double 
 */
double	ft_veclen(t_vec v);

/**
 * @brief multiply vector
 * 
 * @param v 
 * @param l 
 * @return t_vec 
 */
t_vec	ft_vecmul(t_vec v, double l);

/**
 * @brief divide vector
 * 
 * @param v 
 * @param l 
 * @return t_vec 
 */
t_vec	ft_vecdiv(t_vec v, double l);

#endif
