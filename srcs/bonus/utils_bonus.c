/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 06:32:12 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/18 12:57:29 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	init(t_pip_bonus *pipex, int ac, char **av, char **ep)
{
	pipex->argc = ac;
	pipex->argv = av;
	pipex->envp = ep;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		pipex->here_doc_flag = TRUE;
		pipex->outfile_fd = open_file(av[ac - 1], 2);
	}
	else 
	{
		pipex->infile_fd = open_file(av[1], 1);
		if (pipex->infile_fd < -1)
			error_bonus(ERR_FILEIN, pipex->argv[1]);
		pipex->outfile_fd = open_file(av[ac - 1], 1);
	}
}

void	close_fds_bonus(t_pip_bonus *pipex)
{
	if (pipex->infile_fd > -1)
		close(pipex->infile_fd);
	if (pipex->outfile_fd > -1)
		close(pipex->outfile_fd);
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
		handle_error_bonus(ERR_MEMORY, pipex);
}

int	open_file(char *file, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(file, O_RDONLY, 0777);
	else if (i == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		fd = open(file , O_WRONLY | O_CREAT | O_APPEND, 0777);
	return (fd);
}

char	*strjoin_pipex(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (str == ALLOC_FAIL)
		return (ALLOC_FAIL);
	while (s1 != NULL && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[++j] != '\0')
		str[i + j] = s2[j];
	return (str);
}
