/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 06:32:12 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/16 09:34:50 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	ft_init(t_pip_bonus *pipex, int ac, char **av, char **ep)
{
	pipex->argc = ac;
	pipex->argv = av;
	pipex->envp = ep;
}

void	free_bonus(t_pip_bonus *pipex)
{
	if (pipex->infile_fd > -1)
		close(pipex->infile_fd);
	if (pipex->outfile_fd > -1)
		close(pipex->outfile_fd);
	if (pipex->envp != NULL)
		free_arr(pipex->envp);
	if (pipex->argv != NULL)
		free_arr(pipex->argv);
	if (pipex->envp_path != NULL)
		free_arr(pipex->envp_path);
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
	if (pipex->envp_path == ALLOC_FAIL)
		handle_error(ERR_MEMORY, pipex);
}
