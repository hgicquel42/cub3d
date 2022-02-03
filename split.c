/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:03:57 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 17:09:16 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"
#include <stdlib.h>

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
 * @param c splitter
 * @param r result
 * @return int count 
 */
static int	ft_split_copy(char *s, char c, char *r)
{
	int	l;

	l = 0;
	while (s[l] && s[l] != c)
		ft_chrcpy(r, s, l++);
	if (r)
		r[l] = 0;
	return (l);
}

/**
 * @brief count and copy strings
 * 
 * @param s input
 * @param c splitter
 * @param p result 
 * @return int count
 */
static int	ft_split_loop(char *s, char c, char **p)
{
	int		l;
	int		l2;
	char	*r;

	l = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		l2 = ft_split_copy(s, c, NULL);
		if (p)
		{
			r = malloc(l2 + 1);
			if (!r)
				return (l);
			if (ft_split_copy(s, c, r) != l2)
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
 * @param c splitter
 * @return char** result
 */
char	**ft_split(char *s, char c)
{
	int		l;
	char	**p;

	l = ft_split_loop(s, c, NULL);
	p = malloc((l + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	if (ft_split_loop(s, c, p) != l)
		return (NULL);
	return (p);
}
