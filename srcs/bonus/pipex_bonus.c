/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 06:24:10 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/18 12:45:09 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	execute_heredoc(t_pip_bonus *pipex)
{
	char	*str;

	str = NULL;
	while (1)
	{
		write(1, "\033[31mEvilPipex 👻> ", 22);
		write(1, "\033[0m", 5);
		str = get_next_line(STDIN_FILENO);
		if (str == ALLOC_FAIL)
			return (handle_error_bonus(ERR_MEMORY, pipex));
		if (ft_strncmp(pipex->argv[2], str, ft_strlen(pipex->argv[2])) == 0)
		{
			free(str);
			return ;
		}
		write(pipex->hdfd[1], str, ft_strlen(str));
		free(str);
	}
}

void	handle_heredoc(t_pip_bonus *pipex)
{
	int	pid;
	int	status;

	if (pipe(pipex->hdfd) == -1)
		handle_error_bonus(ERR_PIPE, pipex);
	pid = fork();
	if (pid == 0)
	{
		close(pipex->hdfd[0]);
		execute_heredoc(pipex);
		exit (EXIT_SUCCESS);
	}
	else
	{
		close(pipex->hdfd[1]);
		dup2(pipex->hdfd[0], STDIN_FILENO);
		close(pipex->hdfd[0]);
		waitpid(pid, &status, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pip_bonus	*pipex;
	int			return_value;

	return_value = EXIT_SUCCESS;
	if (argc < 5)
		return (EXIT_FAILURE);
	pipex = (t_pip_bonus *)ft_calloc(1, sizeof(t_pip_bonus));
	if (pipex == ALLOC_FAIL)
		handle_error_bonus(ERR_MEMORY, pipex);
	init(pipex, argc, argv, envp);
	get_envp_path(pipex);
	if (pipex->here_doc_flag == TRUE)
		handle_heredoc(pipex);
	else
		dup2(pipex->infile_fd, STDIN_FILENO);
	return_value = handle_pipe(pipex);
	free_bonus(pipex);
	return (return_value);
}
