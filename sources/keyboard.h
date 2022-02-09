/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:19:07 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 18:42:24 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

# include <stdbool.h>

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	al;
	bool	ar;
	bool	shift;
}	t_keys;

/**
 * @brief init keys
 * 
 * @param keys 
 */
void	ft_keys_init(t_keys *keys);

#endif
