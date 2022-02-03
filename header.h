/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:03:58 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 19:06:49 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef struct s_header
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	char	*cell;
}	t_header;

/**
 * @brief parse map headers
 * 
 * @param lines 
 * @return int 
 */
int	ft_header(char **lines);

#endif
