/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:03:33 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/03 10:57:36 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Converts an uppercase alphabet character to its lowercase equivalent
/// @param c the character to convert to lower case
/// @return Decimal value of the corresponding lowercase character
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
