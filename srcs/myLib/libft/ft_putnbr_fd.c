/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:29:32 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/02 22:42:04 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Prints number on the terminal, similat to ITOA()
/// @param n The number to be printed
/// @param fd The file descriptor
void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	nbr[14];

	i = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	else if (n == 0)
		nbr[i++] = 48;
	while (n > 0)
	{
		nbr[i++] = n % 10 + 48;
		n /= 10;
	}
	while (--i >= 0)
		ft_putchar_fd(nbr[i], fd);
}
