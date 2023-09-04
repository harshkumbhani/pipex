/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:09:09 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/06 16:27:02 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Locates the first occurence of c (converted to unsigned char) in s
/// @param s The string to check the occurence
/// @param c Check character
/// @param n Number of bytes to be checked for occurence of c in s
/// @return pointer to the byte locater of NULL if no such byte exists within n 
///			bytes
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n != 0)
	{
		if (*str == (unsigned char) c)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
