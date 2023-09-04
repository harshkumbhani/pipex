/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:24:04 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/04/07 13:35:42 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Converts charcters to integers
/// 		Inital whitespaces are not skipped
///			Only either sign(+ || -) is allowed with occurence of once 
/// @param str The string to be converted to integers
/// @return return an integer 
int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((char )str[i] >= '0' && (char)str[i] <= '9')
	{
		num = 10 * num + ((char)str[i] - '0');
		i++;
	}
	return (num * sign);
}

//int	ft_isspace(char	c)
//{
//	if ((c >= 9 && c <= 13) || c == 32)
//		return	(1);
//	return (0);
//}