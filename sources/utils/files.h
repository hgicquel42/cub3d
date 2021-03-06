/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:18:58 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/08 16:29:13 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

# include <stdbool.h>

/**
 * @brief safely count length of file
 * 
 * @param file
 * @param result
 * @return bool false if it failed
 */
bool	ft_seek(int file, int *result);

/**
 * @brief safely read file
 * 
 * @param filename
 * @param result
 * @return bool false if it failed 
 */
bool	ft_read(char *path, char **result);

#endif
