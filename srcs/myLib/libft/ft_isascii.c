/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:05:50 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/03 10:54:01 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Checks if c is an ASCII character
/// @param c Test character
/// @return 1 if c is ASCII else 0
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
