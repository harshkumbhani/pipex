/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:34:34 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/14 21:40:16 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	print_all_cmds(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->cmd1_args[++i])
	{
		if (pipex->cmd1_args[i] == NULL)
			printf("cmd1_Args[%d] : NULL\n", i);
		printf("cmd1_Args[%d] : %s\n", i, pipex->cmd1_args[i]);
	}
	i = -1;
	while (pipex->cmd2_args[++i])
		printf("cmd2_Args[%d] : %s\n", i, pipex->cmd2_args[i]);
}

void	ft_close_fds(t_pipex *pipex)
{
	if (pipex->infile_fd > -1)
		close(pipex->infile_fd);
	if (pipex->outfile_fd > -1)
		close(pipex->outfile_fd);
}

void	free_all(t_pipex *pipex)
{
	int	i;

	i = -1;
	ft_close_fds(pipex);
	if (pipex->cmd1_args != NULL)
		free_arr(pipex->cmd1_args);
	if (pipex->cmd2_args != NULL)
		free_arr(pipex->cmd2_args);
	if (pipex->envp_path != NULL)
		free_arr(pipex->envp_path);
	while (++i < 2)
		free(pipex->cmd_paths[i]);
	free(pipex);
}
