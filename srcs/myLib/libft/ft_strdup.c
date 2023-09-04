/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:00:23 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/02 23:47:33 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies string s1 to a sufficiently allocated memory
/// @param s1 The strig to be copied 
/// @return a pointer to the copied string
char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;

	len = ft_strlen(s1) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	if (str)
		ft_memcpy(str, s1, len);
	return (str);
}
