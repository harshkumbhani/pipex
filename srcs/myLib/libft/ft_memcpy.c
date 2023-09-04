/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:31:50 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/02 22:21:14 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief This function copies the specified number of bytes from the source 
///   memory block to the destination memory block. The function assumes  
///   that both memory blocks are already allocated and that their sizes are at 
///   least n bytes.The function does not check for overlap between the source  
///   and destination memory blocks
/// @param dst Pointer to destination memory block
/// @param src Pointer to source memory block
/// @param n Number of bytes to copy
/// @return A pointer to memory destination block
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((const char *) src)[i];
		i++;
	}
	return (dst);
}

/*
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*dest;
	const unsigned char 	*source;
	size_t					i;

	i = 0;
	dest = (unsigned char *) dst;
	source = (const unsingned char *) src;
	
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
*/