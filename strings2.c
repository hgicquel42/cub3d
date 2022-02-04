/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:44:11 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/04 08:44:23 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_strdup(char *s)
{
	int		size;
	char	*str;

	size = ft_strlen(s) + 1;
	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	str = ft_memcpy(str, s, size);
	return (str);
}

char	*cut_space(char *str)
{
	int	i;
	int	j;
	int	k;
	int	b;

	i = 0;
	j = 0;
	b = 0;
	while (str[i] && str[i] == ' ')
		i++;
	j = i;
	while (b == 0)
	{
		k = 0;
		while (str[j] && str[j] != ' ')
			j++;
		while (str[j + k] && str[j + k] == ' ')
			k++;
		if (str[j + k] == '\0')
			b = 1;
		j++;
	}
	return (ft_substr(str, i, j));
}