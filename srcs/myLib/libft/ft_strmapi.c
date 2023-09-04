/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:46:08 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/02 23:46:41 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief creates a new string by successive applies function f 
///			to each character of the string s
/// @param s The string to iterate on
/// @param f The function to apply on each character
/// @return The string created from succesvice applications of 'f'
/// 		returns NULL if allocation fails
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	unsigned int	slen;
	char			*dst;

	i = 0;
	slen = ft_strlen(s);
	dst = (char *)ft_calloc(slen + 1, sizeof(char));
	if (!dst)
		return (NULL);
	while (i < slen)
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	return (dst);
}
