/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:38:33 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/03 10:54:04 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Checkts if c is a digit
/// @param c Test character
/// @return 1 if c is digit else 0
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
