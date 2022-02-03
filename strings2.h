/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:29:51 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 18:53:44 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS2_H
# define STRINGS2_H

/**
 * @brief duplicate string
 * 
 * @param s string
 * @return char* result
 */
char	*ft_strdup(char *s);

/**
 * @brief safely duplicate string
 * 
 * @param s string
 * @param r result
 * @return bool false if failed
 */
bool	ft_xstrdup(char *s, char **r);

#endif
