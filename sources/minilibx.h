/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:57:05 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 17:26:27 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include <stdbool.h>
# include "positions.h"

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		width;
	int		height;
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
}	t_mlx;

/**
 * @brief init image data address
 * 
 * @param img img struct
 * @return false if failed
 */
bool	ft_image_init(t_img *img);

/**
 * @brief load xpm into minilibx
 * 
 * @param mlx mlx ptr
 * @param path file
 * @param img img struct
 * @return false if failed
 */
bool	ft_minilibx_load(void *mlx, char *path, t_img *img);

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
