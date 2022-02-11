/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:28:27 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/11 14:41:17 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS2_H
# define STRINGS2_H

# include <stdbool.h>

/**
 * @brief duplicate string
 * 
 * @param s string
 * @return char* result
 */
char	*ft_strdup(char *s);

/**
 * @brief duplicate string until l
 * 
 * @param s string
 * @param l length
 * @return char* result
 */
char	*ft_strldup(char *s, int l);

/**
 * @brief substring s from a to b
 * 
 * @param s string
 * @param a start
 * @param b end
 * @return char* result
 */
char	*ft_substr(char *s, int a, int b);

/**
 * @brief trim string before and after
 * 
 * @param s string
 * @param f ft_isblank
 * @return char* result
 */
char	*ft_strtrim(char *s, bool (*f)(char c));

/**
 * @brief return double tab len
 * 
 * @param tab 
 * @return int 
 */
int		ft_maplen(char **tab);

#endif
