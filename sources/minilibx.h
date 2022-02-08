/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:57:05 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 17:36:17 by hgicquel         ###   ########.fr       */
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
 * @brief load xpm into minilibx
 * 
 * @param mlx mlx ptr
 * @param path file
 * @param img img struct
 * @return false if failed
 */
bool	ft_minilibx_texture(void *mlx, char *path, t_img *img);

/**
 * @brief load xpms into minilibx
 * 
 * @param header 
 * @param mlx mlx struct
 * @return false if failed
 */
bool	ft_minilibx_textures(t_header *header, t_mlx *mlx);

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
