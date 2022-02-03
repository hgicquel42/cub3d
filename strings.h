/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:27:31 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 18:12:33 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

# include <stdbool.h>

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
 * @brief compare two strings until l
 * 
 * @param a string
 * @param b string
 * @param l length
 * @return int comparison
 */
int		ft_strlcmp(char *a, char *b, int l);

/**
 * @brief check if a string ends with another
 * 
 * @param a "map.cub"
 * @param b ".cub"
 * @return true a ends with b
 * @return false a does not end with b
 */
bool	ft_strends(char	*a, char *b);

/**
 * @brief check if a string starts with another
 * 
 * @param a "map.cub"
 * @param b "map"
 * @return true a starts with b
 * @return false a does not starts with b
 */
bool	ft_strstarts(char *a, char *b);

#endif