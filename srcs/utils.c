/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:34:34 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/14 09:34:46 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_all_cmds(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->cmd1_args[++i])
		printf("cmd1_Args[%d] : %s\n", i, pipex->cmd1_args[i]);
	i = -1;
	while (pipex->cmd2_args[++i])
		printf("cmd2_Args[%d] : %s\n", i, pipex->cmd2_args[i]);
}

char	*remove_quotes(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] == '\'' && str[len - 1] == '\'')
	{
		str[len - 1] = '\0';
		return (str + 1);
	}
	return (str);
}

void	free_arr(char	**arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(t_pipex *box)
{
	if (box->infile_fd > -1)
		close(box->infile_fd);
	close(box->outfile_fd);
	if (box->cmd1_args != NULL)
		free_arr(box->cmd1_args);
	if (box->cmd2_args != NULL)
		free_arr(box->cmd2_args);
	if (box->envp_path != NULL)
		free_arr(box->envp_path);
	if (box->cmd1_path != NULL)
		free(box->cmd1_path);
	if (box->cmd2_path != NULL)
		free(box->cmd2_path);
	free(box);
}
