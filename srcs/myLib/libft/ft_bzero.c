/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:31:13 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/04 16:34:01 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief write zeroes to a byte string 
/// @param s string to set zeroed bytes
/// @param n number of bytes to be set zero to
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*	Algoritm 2
void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
*/
