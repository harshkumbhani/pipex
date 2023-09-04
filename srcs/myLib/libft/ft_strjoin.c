/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:24:10 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/02 23:47:16 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Concatenates strings s1 and s1
/// @param s1 String one 
/// @param s2 String 2
/// @return Pointer to new string and NULL if allocation fails
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(size);
	if (!str || (!s1 && !s2))
		return (NULL);
	str = ft_memcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, size);
	return (str);
}

/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*temp;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	temp = str;
	if (!str || (!s1 && !s2))
		return (NULL);
	str = (char *)ft_memcpy(str, s1, ft_strlen(s1));
	str = (char *)ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (str);
}
*/