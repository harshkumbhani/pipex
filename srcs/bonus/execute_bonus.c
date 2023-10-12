/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:40:04 by harsh             #+#    #+#             */
/*   Updated: 2023/10/12 17:22:34 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

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
		if (pipex->tmp == NULL)
			handle_error_bonus(ERR_MEMORY, pipex);
		cmd_path = strjoin_pipex(pipex->tmp, cmd);
		if (cmd_path == NULL)
			handle_error_bonus(ERR_MEMORY, pipex);
		free(pipex->tmp);
		pipex->tmp = NULL;
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	pipex->tmp = NULL;
	return (NULL);
}

void	execute(t_pip_bonus *pipex, int i)
{
	char	*path;
	char	**cmd_split;

	cmd_split = ft_split_pipex(pipex->argv[i], ' ');
	if (cmd_split == NULL)
		handle_error_bonus(ERR_MEMORY, pipex);
	path = find_cmd_path(pipex, cmd_split[0]);
	if (path == NULL)
	{
		ft_putstr_fd("Linr 55", STDERR_FILENO);
		error_bonus(ERR_CMD, cmd_split[0], pipex);
		free_arr(cmd_split);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd_split, pipex->envp) == -1)
	{
		free(path);
		error_bonus(ERR_CMD, cmd_split[0], pipex);
		free_arr(cmd_split);
		exit(EXIT_FAILURE);
	}
	return ;
}
