/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:48:31 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 15:50:59 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>
#include "utils/colors.h"
#include "utils/pointers.h"

/**
 * @brief init header
 * 
 * @param header 
 */
void	ft_header_init(t_header *header)
{
	header->north = NULL;
	header->south = NULL;
	header->east = NULL;
	header->west = NULL;
	header->rfloor = NULL;
	header->rcell = NULL;
	ft_color_init(header->floor);
	ft_color_init(header->cell);
	header->length = 0;
}

/**
 * @brief free header
 * 
 * @param header 
 * @return int 0
 */
int	ft_header_free(t_header *header)
{
	ft_free(header->north);
	ft_free(header->south);
	ft_free(header->east);
	ft_free(header->west);
	ft_free(header->rfloor);
	ft_free(header->rcell);
	return (0);
}
