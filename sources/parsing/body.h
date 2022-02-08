/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   body.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:46:38 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/08 14:58:50 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BODY_H
# define BODY_H

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
