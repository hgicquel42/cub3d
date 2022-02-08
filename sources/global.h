/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:43:36 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 15:37:31 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

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
}				t_header;

typedef struct s_ipos
{
	int	x;
	int	y;
}	t_ipos;

typedef struct s_dpos
{
	double	x;
	double	y;
}	t_dpos;

typedef struct s_player
{
	t_ipos	pos;
	t_dpos	yaw;
}	t_player;

typedef struct s_map
{
	t_header	header;
	char		**lines;
	char		**body;
}				t_map;

typedef struct s_global
{
	t_map		map;
	t_player	player;
}				t_global;

/**
 * @brief init global
 * 
 * @param g global
 */
void	ft_global_init(t_global *g);

/**
 * @brief init global
 * 
 * @param g global
 */
void	ft_global_free(t_global *g);

#endif
