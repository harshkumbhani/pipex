/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:51:34 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/05 10:27:42 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Locates last occurence of (char c) in string c
/// @param s The string to be searched for 
/// @param c The character c
/// @return Pointer to the located character or NULL if c doesnot appear in s
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/* Algorithm 2
	char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	if (*s == (char) c)
		ptr = (char *)s;
	while (*s++)
	{
		if (*s == (char)c)
			ptr = (char *)s;
	}
	return (ptr);
}
*/