/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 06:24:10 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/07/12 23:20:57 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_heredoc(t_pip_bonus *pipex)
{
	char	*str;

	str = NULL;
	while (1)
	{
		write(1, "\033[31mEvilPipex 👻> ", 22);
		write(1, "\033[0m", 5);
		str = get_next_line(STDIN_FILENO);
		if (str == NULL)
			return (handle_error_bonus(ERR_MEMORY, pipex));
		if (ft_strncmp(pipex->argv[2], str, ft_strlen(pipex->argv[2])) == 0)
		{
			free(str);
			return ;
		}
		write(pipex->hdfd[1], str, ft_strlen(str));
		free(str);
	}
	free(str);
}

void	handle_heredoc(t_pip_bonus *pipex)
{
	int	pid;

	if (pipe(pipex->hdfd) == -1)
		handle_error_bonus(ERR_PIPE, pipex);
	pid = fork();
	if (pid == 0)
	{
		close(pipex->hdfd[0]);
		execute_heredoc(pipex);
		close(pipex->hdfd[1]);
		close_fds_bonus(pipex);
		free_bonus(pipex);
		exit (EXIT_SUCCESS);
	}
	else
	{
		close(pipex->hdfd[1]);
		dup2(pipex->hdfd[0], STDIN_FILENO);
		close(pipex->hdfd[0]);
		waitpid(pid, NULL, 0);
	}
}

static int	handle_argc(void)
{
	ft_fprintf(STDERR_FILENO, "Usage 1: ./pipex <infile> \"cmd1\"");
	ft_fprintf(STDERR_FILENO, " \"cmd2\" \"cmd3\" ... \"cmd_n\" <outfile>\n");
	ft_fprintf(STDERR_FILENO, "\nUsage 2: ./pipex here_doc LIMITER cmd");
	ft_fprintf(STDERR_FILENO, " cmd1 <outfile>\n");
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	int			i;
	t_pip_bonus	*pipex;
	int			return_value;

	return_value = EXIT_SUCCESS;
	i = 0;
	if (argc < 5)
		return (handle_argc());
	pipex = (t_pip_bonus *)ft_calloc(1, sizeof(t_pip_bonus));
	if (pipex == NULL)
		handle_error_bonus(ERR_MEMORY, pipex);
	init(pipex, argc, argv, envp);
	if (pipex->here_doc_flag == true)
	{
		i = 3;
		handle_heredoc(pipex);
	}
	else
		i = 2;
	return_value = create_pipes(pipex, i);
	free_bonus(pipex);
	return (return_value);
}
