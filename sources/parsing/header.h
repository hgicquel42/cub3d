/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:14:15 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 14:55:11 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "cub3d.h"

/**
 * @brief parse map header
 * 
 * @param lines map lines
 * @return bool	false if failed 
 */
bool	ft_header_parse(t_global *g, char **lines, t_header *header);

/**
 * @brief init header
 * 
 * @param header 
 */
void	ft_header_init(t_header *header);

/**
 * @brief free header
 * 
 * @param header 
 * @return int 0
 */
int		ft_header_free(t_header *header);

#endif
