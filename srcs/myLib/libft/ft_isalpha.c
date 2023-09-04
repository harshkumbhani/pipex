/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:26:12 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/03 10:53:56 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Checks if c is an alphabet
/// @param c character to be checked
/// @return 1 if c is an alpahbet else returns 0
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
