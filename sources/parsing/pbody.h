/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbody.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:46:38 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/09 19:04:26 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PBODY_H
# define PBODY_H

# include <stdbool.h>
# include "global.h"

/**
 * @brief parse map body
 * 
 * @param g 
 * @return true 
 * @return false 
 */
bool	ft_body_parse(t_global *g, char **body);

#endif
