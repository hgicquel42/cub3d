/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:27:31 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/04 08:45:35 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

# include <stdlib.h>

/**
 * @brief length of a string
 * 
 * @param s string
 * @return int length
 */
int		ft_strlen(char *s);

/**
 * @brief compare two strins
 * 
 * @param a string
 * @param b string
 * @return int comparison
 */
int		ft_strcmp(char *a, char *b);

/**
 * @brief check if a string ends with another
 * 
 * @param a "map.cub"
 * @param b ".cub"
 * @return true a ends with b
 * @return false a does not end with b
 */
int		ft_strends(char	*a, char *b);

char	*ft_substr(char *s, unsigned int start, unsigned int len);

char	*ft_strdup(char *s);

char	*cut_space(char *str);

void	*ft_memcpy(void *dst, const void *src, int n);

#endif