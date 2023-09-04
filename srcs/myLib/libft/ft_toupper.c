/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:34:50 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/03 10:57:41 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Capitialises lower case alphabet
/// @param c the character to capitalise
/// @return Decimal value of the corresponding uppercase character
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
