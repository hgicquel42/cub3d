/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:49:53 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 17:49:56 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

/**
 * @brief load xpm into minilibx
 * 
 * @param mlx mlx ptr
 * @param path file
 * @param img img struct
 * @return false if failed
 */
bool	ft_texture_load(void *mlx, char *path, t_img *img);

/**
 * @brief load xpms into minilibx
 * 
 * @param header 
 * @param mlx mlx struct
 * @return false if failed
 */
bool	ft_textures_load(t_header *header, t_mlx *mlx);

#endif
