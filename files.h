/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:18:58 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/03 16:19:01 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

/**
 * @brief count length of file
 * 
 * @param fd file
 * @param r result
 * @return bool false if it failed
 */
bool	ft_seek(int fd, int *r);

#endif
