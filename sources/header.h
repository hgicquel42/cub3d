/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:47:40 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 15:53:51 by hgicquel         ###   ########.fr       */
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
	char	*rfloor;
	char	*rcell;
	char	floor[3];
	char	cell[3];
	int		length;
}	t_header;

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
