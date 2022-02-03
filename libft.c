/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:59:44 by vpiamias          #+#    #+#             */
/*   Updated: 2022/02/03 14:52:11 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
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
