/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:40:04 by harsh             #+#    #+#             */
/*   Updated: 2023/09/18 15:55:12 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	get_envp_path(t_pip_bonus *pipex)
{
	int	i;

	i = -1;
	while (pipex->envp[++i] != NULL)
	{
		if (ft_strncmp(pipex->envp[i], "PATH", 4) == 0)
		{
			ft_strlcat(pipex->path, pipex->envp[i] + 5,
				ft_strlen(pipex->envp[i]) + 1);
			break ;
		}
	}
	pipex->envp_path = ft_split(pipex->path, ':');
	if (pipex->envp_path == ALLOC_FAIL)
		handle_error_bonus(ERR_MEMORY, pipex);
}

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
	error_bonus(ERR_CMD, cmd);
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
	if (path == NULL)
		exit(EXIT_FAILURE);
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
