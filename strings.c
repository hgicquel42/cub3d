/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:22:07 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 14:25:38 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdbool.h"

/**
 * @brief length of a string
 * 
 * @param s string
 * @return int length
 */
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * @brief compare two strins
 * 
 * @param a string
 * @param b string
 * @return int comparison
 */
int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}

/**
 * @brief check if a string ends with another
 * 
 * @param a "map.cub"
 * @param b ".cub"
 * @return true a ends with b
 * @return false a does not end with b
 */
bool	ft_strends(char	*a, char *b)
{
	int	la;
	int	lb;

	la = ft_strlen(a);
	lb = ft_strlen(b);
	if (la < lb)
		return (false);
	return (!ft_strcmp(a + la - lb, b));
}
