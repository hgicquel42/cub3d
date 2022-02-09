/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:57:05 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 19:21:33 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include <stdbool.h>
# include "positions.h"
# include "image.h"

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
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
 * @param mlx mlx
 * @param img img
 */
void	ft_image_put(t_mlx *mlx, t_img *img);

/**
 * @brief init minilibx
 * 
 * @param mlx mlx struct
 * @return false if failed
 */
bool	ft_minilibx_init(t_mlx *mlx, t_img *img);

/**
 * @brief free minilibx
 * 
 * @param mlx mlx struct
 */
void	ft_minilibx_free(t_mlx *mlx, t_img *img);

#endif
