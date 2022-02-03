/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:49:30 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 16:57:27 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBERS_H
# define NUMBERS_H

/**
 * @brief safe version of ft_atoi
 * 
 * @param s string
 * @param r result
 * @return bool false if it failed
 */
bool	ft_xatoi(char *s, int *r);

#endif