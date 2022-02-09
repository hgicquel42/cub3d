/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:08:11 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 16:58:49 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

#include <math.h>
#include <stdio.h>

/**
 * @brief negate vector
 * 
 * @param v 
 * @return t_vec 
 */
t_vec	ft_vecneg(t_vec v)
{
	return (ft_vec(-v.x, -v.y));
}

/**
 * @brief calculate delta of ray vector
 * 
 * @param v 
 * @return t_vec 
 */
t_vec	ft_vecdelta(t_vec v)
{
	return (ft_vec(fabs(1 / v.x), fabs(1 / v.y)));
}

/**
 * @brief print vector
 * 
 * @param v 
 */
void	ft_vecprint(t_vec v)
{
	printf("(%f, %f)\n", v.x, v.y);
}