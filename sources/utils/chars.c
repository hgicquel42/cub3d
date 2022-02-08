/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:36:54 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 15:07:44 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"

/**
 * @brief check if char is newline
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool	ft_isnline(char c)
{
	return (c == '\n' || c == '\r');
}

/**
 * @brief check if char is a digit
 * 
 * @param c char
 * @return bool
 */
bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * @brief check if char is space or tab
 * 
 * @param c char
 * @return bool
 */
bool	ft_isblank(char c)
{
	return (c == ' ' || c == '\t');
}

/**
 * @brief check if char is blank or newline or vtab
 * 
 * @param c char
 * @return bool
 */
bool	ft_isspace(char c)
{
	return (ft_isnline(c) || ft_isblank(c) || c == '\v');
}
