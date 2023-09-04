/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:30:50 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/02 22:25:45 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief This function compares the first n bytes of two memory areas s1 && s2
/// @param s1 A pointer to the first memory area to compare.
/// @param s2 A pointer to the second memory area to compare.
/// @param n The number of bytes to compare between the two memory areas.
/// @return 0 if two strings are identical else  it returns the difference 
///      between the first two differing bytes, treated as unsigned char values.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n != 0)
	{
		while (n != 0)
		{
			if (*str1 != *str2)
				return (*str1 - *str2);
			str1++;
			str2++;
			n--;
		}
	}
	return (0);
}
