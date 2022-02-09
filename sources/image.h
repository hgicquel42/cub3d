/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:10:14 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 12:20:39 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdbool.h>

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		w;
	int		h;
	int		bpp;
	int		line;
	int		end;
}	t_img;

/**
 * @brief init image data address
 * 
 * @param img img struct
 * @return false if failed
 */
bool	ft_image_init(t_img *i);

#endif
