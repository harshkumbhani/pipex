/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 05:32:25 by harsh             #+#    #+#             */
/*   Updated: 2023/10/12 17:12:05 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	error_bonus(t_errors err, char *cmd_or_file, t_pip_bonus *pipex)
{
	if (err == ERR_INFILE)
	{
		ft_putstr_fd("zsh: no such file or directory: ", 2);
		ft_putendl_fd(cmd_or_file, 2);
	}
	else if (err == ERR_CMD)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putendl_fd(cmd_or_file, 2);
	}
	free_bonus(pipex);
}

void	handle_error_bonus(t_errors err, t_pip_bonus *pipex)
{
	if (err == ERR_ARG)
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
	else if (err == ERR_OUTFILE)
		ft_putstr_fd("Error: Unable to create outfile\n", 2);
	else if (err == ERR_CMD2)
		ft_putstr_fd("Error: Command 2 not found\n", 2);
	else if (err == ERR_MEMORY)
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
	else if (err == ERR_PIPE)
		ft_putstr_fd("Error: Pipe creation failed\n", 2);
	else if (err == ERR_FORK)
		ft_putstr_fd("Error: Fork failed\n", 2);
	else
		ft_putstr_fd("Unkown Error\n", 2);
	free_bonus(pipex);
	exit(EXIT_FAILURE);
}
