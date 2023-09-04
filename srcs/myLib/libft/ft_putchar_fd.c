/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:42:57 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/02 22:41:14 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Prints the character c to the given file descriptor  
/// @param c The character to output
/// @param fd the file descriptor
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
