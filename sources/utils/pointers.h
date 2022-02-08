/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:17:59 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 15:38:30 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTERS_H
# define POINTERS_H

/**
 * @brief count pointer length until NULL
 * 
 * @param p double pointer
 * @return int length
 */
int	ft_ptrlen(void **p);

/**
 * @brief free single pointer
 * 
 * @param p pointer
 * @return int 0 (for better chaining)
 */
int	ft_free(void *p);

/**
 * @brief free single pointers until l  
 * 
 * @param p array
 * @param l length
 * @return int always 0
 */
int	ft_freel(void **p, int l);

/**
 * @brief free double pointer until NULL
 * 
 * @param p double pointer
 * @return int 0 (for better chaining)
 */
int	ft_freep(void **p);

/**
 * @brief free double pointer until l
 * 
 * @param p double pointer
 * @return int 0 (for better chaining)
 */
int	ft_freelp(void **p, int l);

#endif
