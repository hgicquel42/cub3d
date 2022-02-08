/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:43:46 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 15:53:13 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

#include <stdlib.h>
#include "utils/pointers.h"
#include "header.h"

/**
 * @brief init global
 * 
 * @param g global
 */
void	ft_global_init(t_global *g)
{
	g->map.lines = NULL;
	g->map.body = NULL;
	ft_header_init(&g->map.header);
}

/**
 * @brief init global
 * 
 * @param g global
 */
void	ft_global_free(t_global *g)
{
	ft_freep((void **) g->map.lines);
	ft_header_free(&g->map.header);
}
