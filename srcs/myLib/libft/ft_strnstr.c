/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:45:58 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/02 23:46:30 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief function locates the first occurrence of the null-terminated string 
///        needle in the string haystack, where not 
///        more than len characters are searched
/// @param haystack String in which needle is searched for 
/// @param needle substring to be searched 
/// @param len Maximum number of characters to be searched 
/// @return If needle is an empty string, haystack is returned; if needle occurs
///        nowhere in haystack, NULL is returned; otherwise a pointer to the 
///        first character of the first occurrence of needle is returned.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j]
			&& (i + j < len))
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
