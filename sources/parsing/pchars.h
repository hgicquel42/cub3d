/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pchars.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:59:37 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/15 11:26:42 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PCHARS_H
# define PCHARS_H

# include <stdbool.h>

/**
 * @brief check if c is a floor
 * 
 * @param c char
 * @return true 
 * @return false 
 */
bool	ft_isfloor(char c);

/**
 * @brief check if c is a wall
 * 
 * @param c char
 * @return true 
 * @return false 
 */
bool	ft_iswall(char c);

/**
 * @brief check if c is player char
 * 
 * @param c char
 * @return true 
 * @return false 
 */
bool	ft_isplayer(char c);

/**
 * @brief check if c is map char
 * 
 * @param c char
 * @return true 
 * @return false 
 */
bool	ft_ismap(char c);

/**
 * @brief check if c is a body char also '\n
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool	ft_isbody(char c);

#endif
