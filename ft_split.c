/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:55:34 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/03 13:28:51 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_is_char(char c, char d)
{
	if (c == d)
		return (1);
	return (0);
}

static int	ft_count_word(char const *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] && ft_is_char(str[i], c) == 1)
			i++;
		if (str[i] && ft_is_char(str[i], c) == 0)
		{
			word ++;
			while (str[i] && ft_is_char(str[i], c) == 0)
				i++;
		}
	}
	return (word);
}

static char	*ft_malloc_word(char const *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && ft_is_char(str[i], c) == 0)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && ft_is_char(str[i], c) == 0)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**tab;
	int		i;

	i = 0;
	size = ft_count_word(s, c);
	tab = malloc(sizeof(char *) * (size + 1));
	if (tab == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && ft_is_char(*s, c) == 1)
			s++;
		if (*s && ft_is_char(*s, c) == 0)
		{
			tab[i] = ft_malloc_word(s, c);
			if (tab[i] == NULL)
				return (NULL);
			i++;
			while (*s && ft_is_char(*s, c) == 0)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
