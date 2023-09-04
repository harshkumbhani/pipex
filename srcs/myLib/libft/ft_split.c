/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:29:37 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/02 22:10:08 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Counts the number of substrings in a string delimited by a given 
///   character  This function counts the number of substrings in the given  
///   string that are delimited by the given character.
/// @param str The string to search for substrings
/// @param c The delimiter character. 
/// @return The number of substrings in the string
static int	ft_substrcount(const char *str, char c)
{
	int	i;
	int	count;
	int	flag;

	flag = -1;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && flag == -1)
		{
			flag = 1;
			count++;
		}
		else if (str[i] == c)
			flag = -1;
		i++;
	}
	return (count);
}

/// @brief This function finds the next substring in the given string that is 
///     delimited by the given character, The string pointer is updated to
///     point to the next character after the delimiter.
/// @param str A pointer to a pointer to the string to search for substrings.
/// @param c The delimiter character
/// @return A newly allocated string representing the next substring 
///           in the string, or NULL if there are no more substrings.
static char	*ft_nextsubstr(char const **str, char c)
{
	unsigned int	len;
	char			*dststr;

	len = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[len] && (*str)[len] != c)
		len++;
	dststr = ft_substr(*str, 0, len);
	if (!dststr)
		return (NULL);
	*str += len;
	return (dststr);
}

/// @brief This function frees the memory allocated for an array of strings
/// @param s The array of strings to free
/// @param i Index of the last string in the array
static void	ft_free(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

/// @brief Splits a string into substring delimited by a character
/// @param s The string to split
/// @param c The delimiter character
/// @return An array of newly allocated strings representing the substrings  
/// in the string, or NULL if the string is NULL or memory allocation fails.
char	**ft_split(char const *s, char c)
{
	char	**substr;
	int		i;
	int		len;

	i = 0;
	if (s == NULL)
		return (NULL);
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

/*
static int	ft_substrcount(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			i++;
			continue;		
		}
		while (str[i] != '\0')
		{
			if (str[i] == c || str[i+1] == '\0')
			{
				count++;
				break;
			}
			i++;
		}
		i++;
	}
	return (count);
}
*/