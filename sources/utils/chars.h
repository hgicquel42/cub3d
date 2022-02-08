/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:36:54 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 15:07:49 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARS_H
# define CHARS_H

# include <stdbool.h>

/**
 * @brief check if char is newline
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool	ft_isnline(char c);

/**
 * @brief check if char is a digit
 * 
 * @param c char
 * @return bool
 */
bool	ft_isdigit(char c);

/**
 * @brief check if char is space or tab
 * 
 * @param c char
 * @return bool
 */
bool	ft_isblank(char c);

/**
 * @brief check if char is blank or newline or vtab
 * 
 * @param c char
 * @return bool
 */
bool	ft_isspace(char c);

#endif
