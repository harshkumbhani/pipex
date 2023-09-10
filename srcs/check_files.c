/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:45:04 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/10 12:52:49 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_cmd_path(t_pipex *pipex, char **cmd_args)
{
	int		i;
	char	*cmd_path;

	cmd_path = NULL;
	i = -1;
	while (pipex->envp_path[++i] != NULL)
	{
		pipex->tmp = ft_strjoin(pipex->envp_path[i], "/");
		if (pipex->tmp == ALLOC_FAIL)
			handle_error(ERR_MEMORY, pipex);
		cmd_path = ft_strjoin(pipex->tmp, cmd_args[0]);
		if (cmd_path == ALLOC_FAIL)
			handle_error(ERR_MEMORY, pipex);
		free(pipex->tmp);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	pipex->tmp = NULL;
	return (NULL);
}

void	get_envp_path(t_pipex *pipex, char *envp[], char *argv[])
{
	int	i;

	i = -1;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			ft_strlcat(pipex->path, envp[i] + 5, ft_strlen(envp[i]) + 1);
			break ;
		}
	}
	pipex->envp_path = ft_split(pipex->path, ':');
	if (pipex->envp_path == ALLOC_FAIL)
		handle_error(ERR_MEMORY, pipex);
	pipex->cmd1_path = find_cmd_path(pipex, pipex->cmd1_args);
	if (pipex->cmd1_path == NULL)
		handle_error_return(ERR_CMD1, pipex, argv);
	pipex->cmd2_path = find_cmd_path(pipex, pipex->cmd2_args);
	if (pipex->cmd2_path == NULL)
		handle_error(ERR_CMD2, pipex);
}

int	check_files(char *argv[], char *envp[], t_pipex *pipex)
{
	if (access(argv[1], F_OK | R_OK) == -1)
		handle_error(ERR_INFILE, pipex);
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd < 0)
		handle_error_return(ERR_INFILE, pipex, argv);
	pipex->outfile_fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
		handle_error(ERR_OUTFILE, pipex);
	pipex->cmd1_args = ft_split(argv[2], ' ');
	if (pipex->cmd1_args == ALLOC_FAIL)
		handle_error(ERR_MEMORY, pipex);
	pipex->cmd2_args = ft_split(argv[3], ' ');
	if (pipex->cmd2_args == ALLOC_FAIL)
		handle_error(ERR_MEMORY, pipex);
	get_envp_path(pipex, envp, argv);
	return (EXIT_SUCCESS);
}
