/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:34:28 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 16:35:12 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrays.h"

/**
 * @brief creates a parray
 * 
 * @param p array
 * @param l length
 * @return t_parray parray
 */
t_parray	ft_parray(char *p, int l)
{
	t_parray	parray;

	parray.array = p;
	parray.length = l;
	return (parray);
}
