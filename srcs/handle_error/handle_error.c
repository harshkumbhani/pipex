/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:17:15 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/06 15:15:42 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_error(t_errors err, t_pipex *pipex)
{
	if (err == ERR_ARG)
		ft_putstr_fd("Error: Invalid number of arguments\n", 0);
	else if (err == ERR_INFILE)
		ft_putstr_fd("Error: Unable to open infile\n", 0);
	else if (err == ERR_OUTFILE)
		ft_putstr_fd("Error: Unable to create outfile\n", 0);
	else if (err == ERR_CMD1)
		ft_putstr_fd("Error: Command 1 not found\n", 0);
	else if (err == ERR_CMD2)
		ft_putstr_fd("Error: Command 2 not found\n", 0);
	else if (err == ERR_MEMORY)
		ft_putstr_fd("Error: Memory allocation failed\n", 0);
	else if (err == ERR_PIPE)
		ft_putstr_fd("Error: Pipe creation failed\n", 0);
	else if (err == ERR_FORK)
		ft_putstr_fd("Error: Fork failed\n", 0);
	else
		ft_putstr_fd("Unkown Error\n", 0);
	free_all(pipex);
	exit(EXIT_FAILURE);
}
