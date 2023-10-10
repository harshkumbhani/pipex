/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:13:57 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/10/01 23:40:02 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_substrcount(const char *str, char c)
{
	int	i;
	int	count;
	int	flag;
	int	quote;

	flag = -1;
	i = 0;
	quote = 0;
	count = 0;
	while (str != NULL && str[i] != '\0')
	{
		if (str[i] == '\'')
			quote = !quote;
		if (!quote && str[i] != c && flag == -1)
		{
			flag = 1;
			count++;
		}
		else if (!quote && str[i] == c)
			flag = -1;
		i++;
	}
	return (count);
}

static char	*ft_nextsubstr(char const **str, char c)
{
	unsigned int	len;
	char			*dststr;
	int				quote;

	len = 0;
	quote = 0;
	while (**str && **str == c && !quote)
		(*str)++;
	while ((*str)[len] && (quote || (*str)[len] != c))
	{
		if ((*str)[len] == '\'')
			quote = !quote;
		len++;
	}
	if (**str == '\'')
		dststr = ft_substr(*str, 1, len - 2);
	else
		dststr = ft_substr(*str, 0, len);
	if (!dststr)
		return (NULL);
	*str += len;
	return (dststr);
}

static void	ft_free(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

char	**ft_split_pipex(char const *s, char c)
{
	char	**substr;
	int		i;
	int		len;

	i = 0;
	len = ft_substrcount(s, c);
	substr = (char **)ft_calloc((len + 1), sizeof(char *));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = ft_nextsubstr(&s, c);
		if (!substr[i])
		{
			ft_free(substr, i);
			return (NULL);
		}
		i++;
	}
	return (substr);
}
