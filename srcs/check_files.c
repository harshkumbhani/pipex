/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:45:04 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/11 23:18:38 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_cmd_path(t_pipex *pipex, char **cmd_args)
{
	int		i;
	char	*cmd_path;

	printf("cmd_path before ft_Strjoin: %s\n", cmd_args[0]);
	cmd_path = ft_strjoin(cmd_args[0], "\0");
	printf("cmd_path : %s\n", cmd_path);
	free(cmd_path);
	cmd_path = NULL;
	i = -1;
	if (access(cmd_path, F_OK | X_OK) == 0)
		return (cmd_path);
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
	if (pipex->infile_fd > -1)
	{
		pipex->cmd1_path = find_cmd_path(pipex, pipex->cmd1_args);
		if (pipex->cmd1_path == NULL)
			handle_error_return(ERR_CMD1, pipex, argv);
	}
	printf("cmd2_args : %s\n", pipex->cmd2_args[0]);
	pipex->cmd2_path = find_cmd_path(pipex, pipex->cmd2_args);
	if (pipex->cmd2_path == NULL)
		handle_error_return(ERR_CMD2, pipex, argv);
	free_arr(pipex->envp_path);
	pipex->envp_path = NULL;
}

int	check_files(char *argv[], char *envp[], t_pipex *pipex)
{
	access(argv[1], F_OK | R_OK);
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd < 0)
		handle_error_return(ERR_INFILE, pipex, argv);
	pipex->outfile_fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
		handle_error_return(ERR_OUTFILE, pipex, argv);
	pipex->cmd1_args = ft_split(argv[2], ' ');
	if (pipex->cmd1_args == ALLOC_FAIL)
		handle_error(ERR_MEMORY, pipex);
	pipex->cmd2_args = ft_split(argv[3], ' ');
	if (pipex->cmd2_args == ALLOC_FAIL)
		handle_error(ERR_MEMORY, pipex);
	get_envp_path(pipex, envp, argv);
	return (EXIT_SUCCESS);
}
