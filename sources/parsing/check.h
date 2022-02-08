/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:46:38 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/08 13:41:08 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "cub3d.h"

/**
 * @brief parse map body
 * 
 * @param g 
 * @return true 
 * @return false 
 */
bool	ft_body_parse(t_global *g, char **body);

#endif
