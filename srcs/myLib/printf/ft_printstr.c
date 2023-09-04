/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:39:52 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/18 12:47:01 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen_printf(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ft_putstr_printf(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		s = "(null)";
	if (write(1, s, ft_strlen_printf(s)) < 0)
		return (-1);
	len += ft_strlen_printf(s);
	return (len);
}
