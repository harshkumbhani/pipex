/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 06:32:12 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/18 16:46:58 by hkumbhan         ###   ########.fr       */
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
		pipex->infile_fd = open_file(av[1], 0);
		if (pipex->infile_fd < 0)
			error_bonus(ERR_INFILE, pipex->argv[1]);
		pipex->outfile_fd = open_file(av[ac - 1], 1);
	}
	get_envp_path(pipex);
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

int	open_file(char *file, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(file, O_RDONLY);
	else if (i == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
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
