/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:22:06 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 17:23:03 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
#define MEMORY_H

/**
 * @brief copy src into dst until l
 * @warning unsafe if overlap
 * @param src source
 * @param dst destination
 * @param l length
 */
void	ft_strlcpy(char *src, char *dst, int l);

#endif
