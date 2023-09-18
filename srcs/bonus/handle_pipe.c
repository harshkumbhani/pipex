/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:26:37 by harsh             #+#    #+#             */
/*   Updated: 2023/09/18 12:49:06 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	first_child(t_pip_bonus *pipex, int i)
{
	int	pid1;

	pid1 = fork();
	if (pid1 < 0)
		handle_error_bonus(ERR_FORK, pipex);
	if (pid1 == 0)
	{
		close(pipex->fd[0]);
		if (pipex->infile_fd < 0)
		{
			free_bonus(pipex);
			exit(EXIT_FAILURE);
		}
		dup2(pipex->fd[1], STDOUT_FILENO);
		close(pipex->fd[1]);
		close_fds_bonus(pipex);
		if (execute(pipex, i) == -1)
		{
			free_bonus(pipex);
			exit(EXIT_FAILURE);
		}
	}
}

static void middle_child(t_pip_bonus *pipex, int i)
{
	int pid2;

	close(pipex->fd[1]);
	dup2(pipex->fd[0], STDIN_FILENO);
	close(pipex->fd[0]);
	if (pipe(pipex->fd) == -1)
		handle_error_bonus(ERR_PIPE, pipex);
	pid2 = fork();
	if (pid2 < 0)
		handle_error_bonus(ERR_FORK, pipex);
	if (pid2 == 0)
	{
		close(pipex->fd[0]);
		dup2(pipex->fd[1], STDOUT_FILENO);
		close_fds_bonus(pipex);
		close(pipex->fd[1]);
		if (execute(pipex, i) == -1)
		{
			free_bonus(pipex);
			exit(EXIT_FAILURE);
		}
	}
}

static void last_child(t_pip_bonus *pipex, int i)
{
	int	pid3;

	pid3 = fork();
	if (pid3 == -1)
		handle_error_bonus(ERR_FORK, pipex);
	if (pid3 == 0)
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		dup2(pipex->outfile_fd, STDOUT_FILENO);
		close(pipex->fd[0]);
		close_fds_bonus(pipex);
		if (execute(pipex, i) == -1)
		{
			free_bonus(pipex);
			exit(127);
		}
	}
}

void	ft_wait(int i)
{
	while (i-- >= 2)
		waitpid(0, NULL, 0);
}

int	handle_pipe(t_pip_bonus *pipex)
{
	// int	status;
	int	i;

	// status = EXIT_SUCCESS;
	if (pipe(pipex->fd) == -1)
		handle_error_bonus(ERR_PIPE, pipex);
	if (pipex->here_doc_flag == TRUE)
		i = 3;
	else
		i = 2;
	first_child(pipex, i);
	close(pipex->fd[1]);
	i++;
	while (i < pipex->argc - 2)
		middle_child(pipex, i++);
	last_child(pipex, i);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	ft_wait(i);
	return (EXIT_SUCCESS);
}
