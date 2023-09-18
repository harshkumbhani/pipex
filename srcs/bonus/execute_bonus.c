/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:40:04 by harsh             #+#    #+#             */
/*   Updated: 2023/09/18 12:54:50 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_cmd_path(t_pip_bonus *pipex, char *cmd)
{
	int		j;
	char	*cmd_path;

	cmd_path = strjoin_pipex(cmd, "");
	if (access(cmd_path, F_OK | X_OK) == 0)
		return (cmd_path);
	free(cmd_path);
	cmd_path = NULL;
	j = -1;
	while (pipex->envp_path[++j] != NULL)
	{
		pipex->tmp = strjoin_pipex(pipex->envp_path[j], "/");
		if (pipex->tmp == ALLOC_FAIL)
			handle_error_bonus(ERR_MEMORY, pipex);
		cmd_path = strjoin_pipex(pipex->tmp, cmd);
		if (cmd_path == ALLOC_FAIL)
			handle_error_bonus(ERR_MEMORY, pipex);
		free(pipex->tmp);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	pipex->tmp = NULL;
	return (NULL);
}

int	execute(t_pip_bonus *pipex, int i)
{
	char	*path;
	char	**cmd_split;

	cmd_split = ft_split_pipex(pipex->argv[i], ' ');
	if (cmd_split == ALLOC_FAIL)
		handle_error_bonus(ERR_MEMORY, pipex);
	path = find_cmd_path(pipex, cmd_split[0]);
	if (execve(path, cmd_split, pipex->envp) == -1)
	{
		error_bonus(ERR_CMD, cmd_split[0]);
		free_bonus(pipex);
		free_arr(cmd_split);
		free(path);
		return (-1);
	}
	return (EXIT_SUCCESS);
}
