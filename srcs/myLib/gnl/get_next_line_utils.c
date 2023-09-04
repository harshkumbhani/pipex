/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:37:11 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/07 14:10:41 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *str, int c)
{
	int	i;

	i = -1;
	if (str == NULL)
		return (NULL);
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*result;
	size_t		len_s1;
	size_t		len_s2;

	len_s1 = ft_strlen_gnl(s1);
	len_s2 = ft_strlen_gnl(s2);
	if (!s1 && !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (result == ALLOC_FAIL)
		return (ALLOC_FAIL);
	ft_memcpy_gnl(result, s1, ft_strlen_gnl(s1));
	ft_memcpy_gnl(result + ft_strlen_gnl(s1), s2, ft_strlen_gnl(s2));
	result[ft_strlen_gnl(s1) + ft_strlen_gnl(s2)] = '\0';
	free(s1);
	return (result);
}

void	*ft_memcpy_gnl(void *dst, void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}
