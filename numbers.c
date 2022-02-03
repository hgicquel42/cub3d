/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:36:04 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 14:49:12 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "chars.h"

/**
 * @brief safe version of ft_atoi
 * 
 * @param s string
 * @param r result
 * @return bool false if it failed
 */
bool	ft_xatoi(char *s, int *r)
{
	int	i;
	int	x;
	int	m;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	m = 1;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			m = -1;
	while (ft_isdigit(s[i]))
		x = (x * 10) + (m * (s[i++] - '0'));
	if (s[i])
		return (false);
	*r = x;
	return (true);
}
