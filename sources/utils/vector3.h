/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:07:51 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 16:58:14 by hgicquel         ###   ########.fr       */
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
 * @brief print vector
 * 
 * @param v 
 */
void	ft_vecprint(t_vec v);

#endif
