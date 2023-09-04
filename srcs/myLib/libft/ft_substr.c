/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:47:29 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/20 10:42:24 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Returns a newly allocated substring
/// @param s the original string
/// @param start the starting position of the substring
/// @param len the length of the substring
/// @return A newly allocated string representing the substring
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *) ft_calloc(len + 1, sizeof(char));
	if (str)
		ft_memcpy(str, s + start, len);
	return (str);
}
