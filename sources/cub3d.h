/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:11:32 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 18:13:13 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

# include "global.h"
# include "utils/chars.h"
# include "utils/numbers.h"
# include "utils/strings.h"
# include "utils/pointer.h"
# include "utils/files.h"
# include "utils/split.h"
# include "utils/print.h"
# include "parsing/pchars.h"
# include "parsing/header.h"
# include "parsing/color.h"
# include "parsing/check.h"

// # include "check.h"
// # include "game.h"
// # include "minilibx-linux/mlx.h"

// typedef struct s_img
// {
// 	void	*img_ptr;
// 	char	*img_data;
// 	int		bpp;
// 	int		line_size;
// 	int		endian;
// }				t_img;

// typedef struct s_mlx
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	t_img	img[4];
// }				t_mlx;

// int		check_char(char c);

// int		check_wall_char(t_global *g);

// int		check_color(char *color);

// int		check_player(t_global *g);

// int		check_map_info(t_global *g);

// int		check_map(t_global *g);

// int		run_game(t_global *g);

#endif