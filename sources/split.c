/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:03:57 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/04 14:11:55 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief copy s[i] in r[i] only if r != NULL
 * 
 * @param r r
 * @param s s
 * @param i i
 */
static void	ft_chrcpy(char *r, char *s, int i)
{
	if (r)
		r[i] = s[i];
}

/**
 * @brief count and copy chars
 * 
 * @param s input
 * @param f splitter
 * @param r result
 * @return int count 
 */
static int	ft_split_copy(char *s, bool (*f)(char), char *r)
{
	int	l;

	l = 0;
	while (s[l] && !f(s[l]))
		ft_chrcpy(r, s, l++);
	if (r)
		r[l] = 0;
	return (l);
}

/**
 * @brief count and copy strings
 * 
 * @param s input
 * @param f splitter
 * @param p result 
 * @return int count
 */
static int	ft_split_loop(char *s, bool (*f)(char), char **p)
{
	int		l;
	int		l2;
	char	*r;

	l = 0;
	while (*s)
	{
		while (f(*s))
			s++;
		l2 = ft_split_copy(s, f, NULL);
		if (p)
		{
			r = malloc(l2 + 1);
			if (!r)
				return (l);
			if (ft_split_copy(s, f, r) != l2)
				return (l);
			p[l] = r;
		}
		s += l2;
		l++;
	}
	if (p)
		p[l] = 0;
	return (l);
}

/**
 * @brief splits string according to char
 * @warning produces leaks if error
 * @param s input
 * @param f splitter
 * @return char** result
 */
char	**ft_split(char *s, bool (*f)(char))
{
	int		l;
	char	**p;

	l = ft_split_loop(s, f, NULL);
	p = malloc((l + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	if (ft_split_loop(s, f, p) != l)
		return (NULL);
	return (p);
}
