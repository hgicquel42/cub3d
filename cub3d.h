/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:11:32 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 10:47:10 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "strings.h"
# include "files.h"
# include "split.h"
# include "print.h"
# include "number.h"
# include "check.h"
# include "game.h"
# include "minilibx-linux/mlx.h"

typedef struct s_header
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	char	*cell;
}				t_header;

typedef struct s_map
{
	t_header	header;
	char		**map;
}				t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		line_size;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img[4];
}				t_mlx;

typedef struct s_global
{
	t_map	xmap;
	t_mlx	mlx;
	int		i_start_map;
}				t_global;

int		check_char(char c);

int		check_wall_char(t_global *g);

int		check_color(char *color);

int		check_player(t_global *g);

int		check_map_info(t_global *g);

int		check_map(t_global *g);

int		ft_error(char *s);

int	run_game(t_global *g);

#endif