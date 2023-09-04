/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:16:27 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/06 18:31:22 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocates some amount of memory and fills it with byte 0 
/// @param count number of objects
/// @param size size of one object 
/// @return pointer to allocated memory
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && (size * count) / count != size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
