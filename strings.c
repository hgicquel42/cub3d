/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:22:07 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/04 08:46:02 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
# include <stdlib.h>

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
 * @brief compare two strings
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
int	ft_strends(char	*a, char *b)
{
	int	la;
	int	lb;

	la = ft_strlen(a);
	lb = ft_strlen(b);
	if (la < lb)
		return (-1);
	if (ft_strcmp(a + la - lb, b) != 0)
		return (-1);
	return (0);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char			*str;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (len > i)
		len = i;
	if (start > i)
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, int n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (src == NULL || dst == NULL)
		return (dst);
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	while (n > 0)
	{
		n--;
		s2[n] = s1[n];
	}
	return (dst);
}
