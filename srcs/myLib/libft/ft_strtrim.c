/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:16:14 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/03 10:57:23 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Function trimes the characters in set 
///			from beginning and end of string s1
/// @param s1 THe string to be trimmed
/// @param set The set of characters to be trimmed
/// @return a copy of trimmed string
char	*ft_strtrim(const char *s1, char const *set)
{
	char	*end;
	char	*str;

	end = (char *) s1 + ft_strlen(s1) - 1;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (end > s1 && ft_strchr(set, *end))
		end--;
	str = (char *)malloc((end - s1 + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, end - s1 + 2);
	return (str);
}
