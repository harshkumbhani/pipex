/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:26:37 by harsh             #+#    #+#             */
/*   Updated: 2024/07/09 08:48:00 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	open_infile(t_pip_bonus *pipex)
{
	if (pipex->here_doc_flag == false)
	{
		pipex->infile_fd = open_file(pipex->argv[1], 0);
		if (pipex->infile_fd < 0)
			error_bonus(ERR_INFILE, pipex->argv[1], pipex);
	}
	dup2(pipex->infile_fd, STDIN_FILENO);
}

void	first_child(t_pip_bonus *pipex, int i)
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
		open_infile(pipex);
		dup2(pipex->fd[1], STDOUT_FILENO);
		close(pipex->fd[1]);
		close_fds_bonus(pipex);
		execute(pipex, i);
	}
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		close(pipex->fd[0]);
	}
}

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
		close(pipex->fd[1]);
		close_fds_bonus(pipex);
		execute(pipex, i);
	}
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		close(pipex->fd[0]);
	}
}

void	last_child(t_pip_bonus *pipex, int i)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		handle_error_bonus(ERR_PIPE, pipex);
	if (pid == 0)
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		dup2(pipex->outfile_fd, STDOUT_FILENO);
		close(pipex->fd[0]);
		close_fds_bonus(pipex);
		execute(pipex, i);
	}
}

int	create_pipes(t_pip_bonus *pipex, int i)
{
	int	status;
	int	loop;

	loop = -1;
	status = EXIT_SUCCESS;
	first_child(pipex, i);
	i++;
	while (i < pipex->argc - 2)
	{
		create_children(pipex, i);
		i++;
	}
	last_child(pipex, i);
	while (++loop < pipex->argc - 2)
		waitpid(0, NULL, 0);
	close_fds_bonus(pipex);
	return (status);
}
