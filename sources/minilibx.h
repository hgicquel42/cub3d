/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:57:05 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 23:10:58 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include <stdbool.h>
# include "positions.h"
# include "header.h"

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		w;
	int		h;
	int		bpp;
	int		line;
	int		end;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	t_ipos	screen;
	t_img	img;
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
}	t_mlx;

/**
 * @brief init image data address
 * 
 * @param img img struct
 * @return false if failed
 */
bool	ft_image_init(t_img *img);

/**
 * @brief put image to window
 * 
 * @param mlx mlx struct
 * @param img img struct
 */
void	ft_image_put(t_mlx *mlx, t_img *img);

/**
 * @brief init minilibx
 * 
 * @param mlx mlx struct
 * @return false if failed
 */
bool	ft_minilibx_init(t_mlx *mlx);

/**
 * @brief free minilibx
 * 
 * @param mlx mlx struct
 */
void	ft_minilibx_free(t_mlx *mlx);

#endif
