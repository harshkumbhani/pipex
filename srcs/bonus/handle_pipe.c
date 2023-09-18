/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:26:37 by harsh             #+#    #+#             */
/*   Updated: 2023/09/18 16:46:25 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	create_children(t_pip_bonus *pipex, int i)
{
	int	pid;

	if (pipe(pipex->fd) == -1)
		handle_error_bonus(ERR_PIPE, pipex);
	pid = fork();
	if (pid == -1)
		handle_error_bonus(ERR_FORK, pipex);
	if (pid == 0)
	{
		close(pipex->fd[0]);
		dup2(pipex->fd[1], STDOUT_FILENO);
		if (execute(pipex, i) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	create_pipes(t_pip_bonus *pipex, int i)
{
	int	status;

	status = EXIT_SUCCESS;
	while (i < pipex->argc - 2)
	{
		create_children(pipex, i);
		i++;
	}
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	dup2(pipex->outfile_fd, STDOUT_FILENO);
	execute(pipex, i);
	return (status);
}
