/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:45:18 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/18 10:15:51 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_child(t_pipex *pipex, char *envp[])
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		handle_error(ERR_FORK, pipex);
	if (pipex->pid1 == 0)
	{
		close(pipex->fd[0]);
		if (pipex->infile_fd < 0 || pipex->cmd_paths[0] == NULL)
		{
			free_all(pipex);
			exit(EXIT_FAILURE);
		}
		dup2(pipex->infile_fd, STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);
		close(pipex->fd[1]);
		ft_close_fds(pipex);
		if (execve(pipex->cmd_paths[0], pipex->cmd1_args, envp) == -1)
		{
			free_all(pipex);
			exit(EXIT_FAILURE);
		}
	}
}

static void	second_child(t_pipex *pipex, char *envp[])
{
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		handle_error(ERR_FORK, pipex);
	if (pipex->pid2 == 0)
	{
		close(pipex->fd[1]);
		if (pipex->outfile_fd < 0 || pipex->cmd_paths[1] == NULL)
		{
			free_all(pipex);
			exit(127);
		}
		dup2(pipex->fd[0], STDIN_FILENO);
		dup2(pipex->outfile_fd, STDOUT_FILENO);
		close(pipex->fd[0]);
		ft_close_fds(pipex);
		if (execve(pipex->cmd_paths[1], pipex->cmd2_args, envp) == -1)
		{
			free_all(pipex);
			exit(127);
		}
	}
}

static void	create_child_process(t_pipex *pipex, char *envp[])
{
	if (pipex->infile_fd >= 0)
		first_child(pipex, envp);
	second_child(pipex, envp);
}

int	do_pipe(t_pipex *pipex, char *envp[])
{
	int	status;

	status = EXIT_SUCCESS;
	if (pipe(pipex->fd) == -1)
		handle_error(ERR_PIPE, pipex);
	create_child_process(pipex, envp);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, &status, 0);
	status = WEXITSTATUS(status);
	return (status);
}
