/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:33:56 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 14:11:09 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi(char *str)
{
	long	nbr;
	int		i;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == 32 || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	nbr = nbr * sign;
	nbr = (int)nbr;
	return (nbr);
}

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