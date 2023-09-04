/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:24:22 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/02 16:42:59 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Counts the number of digits in an integer, which is equal to the
/// number of characters required to store the integer including the sign
/// @param n Integer for which digits are counted
/// @return An integer representing the number of bytes (including sign) needed
/// to store the integer.
static int	ft_digitcount(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

/// @brief Converts an integer to string
/// @param n The integer to convert	
/// @return A newly allocated string representing the given integer.
/// The string must be freed by the caller.
char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	num = n;
	len = ft_digitcount(n);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	if (num == 0)
		str[0] = '0';
	while (num != 0)
	{
		str[--len] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
