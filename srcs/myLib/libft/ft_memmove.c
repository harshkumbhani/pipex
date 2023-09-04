/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:21:25 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/02 22:15:02 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies a block of memory from one location to another
///		This function copies the specified number of bytes from the source 
///		memory block to the destination memory block. Unlike memcpy(), 
///		this function ensures that the memory blocks do not overlap by copying 
///		the bytes in reverse order if necessary.
/// @param dst A pointer to destination memory block
/// @param src A pointer to source memory block
/// @param len The number of bytes to copy
/// @return A pointer to destination memory block
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *) dst;
	s = (const char *)src;
	if (!d && !s)
		return (NULL);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len - 1;
		s += len - 1;
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}
