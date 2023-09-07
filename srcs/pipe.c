/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:45:18 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/07 13:53:59 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_pipe(t_pipex *pipex, char *envp[])
{
	(void)envp;
	if (pipe(pipex->fd) == -1)
		handle_error(ERR_PIPE, pipex);
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		handle_error(ERR_FORK, pipex);
	if (pipex->pid1 == 0)
	{
		dup2(pipex->infile_fd, STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		execve(pipex->cmd1_path, pipex->cmd1_args, envp);
		exit(EXIT_FAILURE);
	}
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		handle_error(ERR_FORK, pipex);
	if (pipex->pid2 == 0)
	{
		dup2(pipex->fd[0], STDIN_FILENO);
		dup2(pipex->outfile_fd, STDOUT_FILENO);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		execve(pipex->cmd2_path, pipex->cmd2_args, envp);
		exit(EXIT_FAILURE);
	}
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}
