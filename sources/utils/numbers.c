/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:33:56 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/09 10:52:42 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"

#include "utils/chars.h"

/**
 * @brief safely transform string to char number
 * 
 * @param s string
 * @param r result
 * @return false if failed (overflow is fail)
 */
bool	ft_xatoc(char *s, char *r)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (ft_isdigit(s[i]) && x < 255)
		x = (x * 10) + (s[i++] - '0');
	if (x > 255)
		return (false);
	if (s[i])
		return (false);
	*r = x;
	return (true);
}
