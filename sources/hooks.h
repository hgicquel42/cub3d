/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:20:41 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 17:39:45 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "global.h"

int		on_close(t_global *g);

int		on_key(int code, t_global *g);

int		on_loop(t_global *g);

/**
 * @brief create hooks
 * 
 * @param g global
 */
void	ft_minilibx_hook(t_global *g);

#endif
