/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:11:32 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/03 17:33:56 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include "chars.h"
# include "strings.h"
# include "numbers.h"
# include "files.h"

typedef struct s_map
{
	char	**lines;
}	t_map;

typedef struct s_global
{
	t_map	xmap;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*floor_color;
	char	*cell_color;
	char	**map;
	char	*path;
	int		len;
	int		file;
	int		i_start_map;
}	t_global;

char	**ft_split(char const *s, char c);

char	**create_map(t_global *g);

bool	check_map(t_global *g);

int		get_map_info(t_global *g);

char	*ft_strdup(char *s);

int		ft_strlen(char *s);

int		map_size(char **map);

void	add_wall(t_global *g);

char	*ft_substr(char *s, unsigned int start, unsigned int len);

int		ft_atoi(char *str);

#endif