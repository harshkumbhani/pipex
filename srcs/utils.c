/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:34:34 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/11 09:37:23 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (box == NULL)
		return ;
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
