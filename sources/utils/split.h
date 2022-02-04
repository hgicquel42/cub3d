/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:57:01 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/04 14:12:01 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

# include "cub3d.h"

/**
 * @brief splits string according to char
 * @warning produces leaks if error
 * @param s input
 * @param f splitter
 * @return char** result
 */
char	**ft_split(char *s, bool (*f)(char));

#endif
