/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:41:13 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/04 08:43:12 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

/**
 * @brief write string in fd
 * 
 * @param fd file
 * @param s string
 * @return int bytes written or -1 if error
 */
int	ft_putfd(int fd, char *s);

/**
 * @brief write string in stderr
 * 
 * @param s string
 * @return int bytes written or -1 if error
 */
int	ft_puterr(char *s);

#endif
