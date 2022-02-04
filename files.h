/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpiamias <vpiamias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:18:58 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/04 07:50:22 by vpiamias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

/**
 * @brief safely count length of file
 * 
 * @param file
 * @param result
 * @return bool false if it failed
 */
int		ft_seek(int file, int *result);

/**
 * @brief safely read file
 * 
 * @param filename
 * @param result
 * @return bool false if it failed 
 */
int		ft_read(char *filename, char **result);

#endif
