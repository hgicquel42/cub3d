/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:29:53 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 18:53:21 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include <stdlib.h>

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
	r = malloc(ft_strlen(s));
	if (!r)
		return (NULL);
	while (*s)
		r[i++] = *s++;
	r[i] = 0;
	return (r);
}

/**
 * @brief safely duplicate string
 * 
 * @param s string
 * @param r result
 * @return bool false if failed
 */
bool	ft_xstrdup(char *s, char **r)
{
	*r = ft_strdup(s);
	return (*r != NULL);
}
