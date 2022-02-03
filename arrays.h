/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:34:16 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 16:39:00 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYS_H
# define ARRAYS_H

typedef struct s_parray
{
	int		length;
	char	*array;
}	t_parray;

/**
 * @brief creates a parray
 * 
 * @param p array
 * @param l length
 * @return t_parray parray
 */
t_parray	ft_parray(char *p, int l);

#endif
