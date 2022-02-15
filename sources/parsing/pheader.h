/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pheader.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:14:15 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/15 12:23:15 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHEADER_H
# define PHEADER_H

# include <stdbool.h>
# include "header.h"
# include "global.h"

/**
 * @brief parse map header
 * 
 * @param lines map lines
 * @return bool	false if failed 
 */
bool	ft_header_parse(t_global *g, char **lines, t_header *header);

/**
 * @brief Return i at start of body
 * 
 * @param array 
 * @return int 
 */
int		ft_header_size(char *array);

#endif
