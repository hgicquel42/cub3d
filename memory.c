/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:22:17 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 17:22:53 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief copy src into dst until l
 * @warning unsafe if overlap
 * @param src source
 * @param dst destination
 * @param l length
 */
void	ft_strlcpy(char *src, char *dst, int l)
{
	int	i;

	i = 0;
	while (i < l)
		dst[i] = src[i];
}
