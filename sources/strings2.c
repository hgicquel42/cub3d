/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:44:11 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 14:12:15 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief duplicate string
 * 
 * @param s string
 * @return char* result
 */
char	*ft_strdup(char *s)
{
	int		i;
	char	*r;

	if (!s)
		return (NULL);
	r = malloc(ft_strlen(s) + 1);
	if (!r)
		return (NULL);
	while (*s)
		r[i++] = *s++;
	r[i] = 0;
	return (r);
}

/**
 * @brief duplicate string until l
 * 
 * @param s string
 * @param l length
 * @return char* result
 */
char	*ft_strldup(char *s, int l)
{
	int		i;
	char	*r;

	if (!s)
		return (NULL);
	r = malloc(l + 1);
	if (!r)
		return (NULL);
	while (*s && i < l)
		r[i++] = *s++;
	r[i] = 0;
	return (r);
}

/**
 * @brief substring s from a to b
 * 
 * @param s string
 * @param a start
 * @param b end
 * @return char* result
 */
char	*ft_substr(char *s, int a, int b)
{
	return (ft_strldup(s + a, b - a));
}

/**
 * @brief trim string before and after
 * 
 * @param s string
 * @param f ft_isblank
 * @return char* result
 */
char	*ft_strtrim(char *s, bool (*f)(char c))
{
	int	a;
	int	b;

	a = 0;
	while (f(s[a]))
		a++;
	b = ft_strlen(s);
	while (b > a && f(s[b - 1]))
		b--;
	return (ft_substr(s, a, b));
}
