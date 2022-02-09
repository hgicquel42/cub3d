/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:57:38 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/09 11:57:44 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

/**
 * @brief frame loop (60Hz)
 * 
 * @param g global
 * @return false if failed
 */
bool	ft_loop(t_global *g);

#endif