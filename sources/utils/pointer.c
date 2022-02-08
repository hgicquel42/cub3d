/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:12:42 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 12:39:54 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief count pointer length until NULL
 * 
 * @param p double pointer
 * @return int length
 */
int	ft_ptrlen(void **p)
{
	int	i;

	i = 0;
	while (p[i])
		i++;
	return (i);
}

/**
 * @brief free single pointer
 * 
 * @param p pointer
 * @return int 0 (for better chaining)
 */
int	ft_free(void *p)
{
	if (p)
		free(p);
	return (0);
}

/**
 * @brief free single pointers until l  
 * 
 * @param p array
 * @param l length
 * @return int always 0
 */
int	ft_freel(void **p, int l)
{
	int	i;

	if (!p)
		return (0);
	i = 0;
	while (i < l)
		ft_free(p[i++]);
	return (0);
}

/**
 * @brief free double pointer until NULL
 * 
 * @param p double pointer
 * @return int 0 (for better chaining)
 */
int	ft_freep(void **p)
{
	int	i;

	if (!p)
		return (0);
	i = 0;
	while (p[i])
		ft_free(p[i++]);
	ft_free(p);
	return (0);
}

/**
 * @brief free double pointer until l
 * 
 * @param p double pointer
 * @return int 0 (for better chaining)
 */
int	ft_freelp(void **p, int l)
{
	int	i;

	if (!p)
		return (0);
	i = 0;
	while (i < l)
		ft_free(p[i++]);
	ft_free(p);
	return (0);
}
