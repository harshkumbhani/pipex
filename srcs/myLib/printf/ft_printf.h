/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:39:45 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/18 12:45:50 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define HEX_C "0123456789ABCDEF"
# define HEX_S "0123456789abcdef"

int	ft_printf(const char *format, ...);
int	ft_formattype(char c, va_list ap, int *i);
int	ft_putchar_printf(char c);
int	ft_strlen_printf(char *s);
int	ft_putstr_printf(char *s);
int	ft_putnbr_printf(long n);
int	ft_putptr_printf(size_t n);
int	ft_puthex_printf(size_t n, char *base);

#endif
