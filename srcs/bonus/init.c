/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:34:59 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/07/09 02:00:22 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	init(t_pip_bonus *pipex, int ac, char **av, char **ep)
{
	pipex->argc = ac;
	pipex->argv = av;
	pipex->envp = ep;
	pipex->fd[0] = -1;
	pipex->fd[1] = -1;
	pipex->hdfd[0] = -1;
	pipex->hdfd[1] = -1;
	pipex->infile_fd = -1;
	pipex->outfile_fd = -1;
	pipex->tmp = NULL;
	pipex->envp_path = NULL;
	pipex->here_doc_flag = false;
	get_envp_path(pipex);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		pipex->here_doc_flag = true;
		pipex->outfile_fd = open_file(av[ac - 1], 2);
	}
	else
		pipex->outfile_fd = open_file(av[ac - 1], 1);
}

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
	if (pipex->envp_path == NULL)
		handle_error_bonus(ERR_MEMORY, pipex);
}
