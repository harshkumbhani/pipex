/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 05:32:25 by harsh             #+#    #+#             */
/*   Updated: 2023/09/18 12:48:06 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_bonus(t_errors_bonus err, char *cmd_or_file)
{
	if (err == ERR_FILEIN)
	{
		ft_putstr_fd("zsh: no such file or directory: ", 0);
		ft_printf("%s\n", cmd_or_file);
	}
	else if (err == ERR_CMD)
	{
		ft_putstr_fd("zsh: command not found: ", 0);
		ft_printf("%s\n", cmd_or_file);
	}
	exit(EXIT_FAILURE);
}

void	handle_error_bonus(t_errors err, t_pip_bonus *pipex)
{
	if (err == ERR_ARG)
		ft_putstr_fd("Error: Invalid number of arguments\n", 0);
	else if (err == ERR_OUTFILE)
		ft_putstr_fd("Error: Unable to create outfile\n", 0);
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
	free_bonus(pipex);
	exit(EXIT_FAILURE);
}
