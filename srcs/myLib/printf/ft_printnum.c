/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:39:48 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/18 12:46:31 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Prints number on the terminal, similat to ITOA()
/// @param n The number to be printed
int	ft_putnbr_printf(long n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar_printf('-');
		if (len < 0)
			return (-1);
		n = -n;
	}
	else if (n == 0)
		return (ft_putchar_printf('0'));
	if (n >= 10)
	{
		len += ft_putnbr_printf(n / 10);
		if (len < 0)
			return (-1);
	}
	len += ft_putchar_printf((n % 10) + 48);
	return (len);
}

int	ft_puthex_printf(size_t n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_puthex_printf(n / 16, base);
		if (len < 0)
			return (-1);
	}
	len += ft_putchar_printf(base[n % 16]);
	return (len);
}

int	ft_putptr_printf(size_t n)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	len += ft_putstr_printf("0x");
	if (len < 0)
		return (-1);
	len += ft_puthex_printf(n, base);
	return (len);
}
