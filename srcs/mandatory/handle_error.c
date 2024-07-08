/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:17:15 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/18 15:19:07 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_error_return(t_errors err, t_pipex *pipex, char *argv[])
{
	if (err == ERR_INFILE)
	{
		ft_putstr_fd("zsh: no such file or directory: ", 1);
		ft_printf("%s\n", argv[1]);
		return ;
	}
	else if (err == ERR_CMD1)
	{
		ft_putstr_fd("zsh: command not found: ", 1);
		ft_printf("%s\n", pipex->cmd1_args[0]);
		return ;
	}
	else if (err == ERR_CMD2)
	{
		ft_putstr_fd("zsh: command not found: ", 1);
		ft_printf("%s\n", argv[3]);
		return ;
	}
	else if (err == ERR_OUTFILE)
	{
		ft_putstr_fd("zsh: no such file or directory: ", 1);
		ft_printf("%s\n", argv[4]);
		return ;
	}
}

void	handle_error(t_errors err, t_pipex *pipex)
{
	if (err == ERR_ARG)
		ft_putstr_fd("Error: Invalid number of arguments\n", 1);
	else if (err == ERR_OUTFILE)
		ft_putstr_fd("Error: Unable to create outfile\n", 1);
	else if (err == ERR_CMD2)
		ft_putstr_fd("Error: Command 2 not found\n", 1);
	else if (err == ERR_MEMORY)
		ft_putstr_fd("Error: Memory allocation failed\n", 1);
	else if (err == ERR_PIPE)
		ft_putstr_fd("Error: Pipe creation failed\n", 1);
	else if (err == ERR_FORK)
		ft_putstr_fd("Error: Fork failed\n", 1);
	else
		ft_putstr_fd("Unkown Error\n", 1);
	free_all(pipex);
	exit(EXIT_FAILURE);
}
