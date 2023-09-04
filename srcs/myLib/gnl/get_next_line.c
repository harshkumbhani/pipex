/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:48:28 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/18 12:42:35 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash = ALLOC_FAIL;
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (ALLOC_FAIL);
	stash = ft_read_file(fd, stash);
	if (stash == ALLOC_FAIL)
		return (ALLOC_FAIL);
	res = ft_get_line(stash);
	if (res[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (free(res), ALLOC_FAIL);
	}
	stash = ft_update_stash(stash);
	return (res);
}

char	*ft_read_file(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	ret = 1;
	while (ret > 0 && !ft_strchr_gnl(stash, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (free(stash), ALLOC_FAIL);
		buffer[ret] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	return (stash);
}

char	*ft_get_line(char *stash)
{
	int		i;
	char	*res;

	i = 0;
	if (!stash)
		return (ALLOC_FAIL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (ALLOC_FAIL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		res[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_update_stash(char *stash)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!stash)
		return (ALLOC_FAIL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
		return (free(stash), ALLOC_FAIL);
	res = malloc(sizeof(char) * (ft_strlen_gnl(stash) - i + 1));
	if (res == ALLOC_FAIL)
		return (free(stash), ALLOC_FAIL);
	i++;
	while (stash[i] != '\0')
		res[j++] = stash[i++];
	res[j] = '\0';
	return (free(stash), res);
}
