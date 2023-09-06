/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:34:34 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/06 14:57:40 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_arr(char	**arr)
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
	if (box->cmd1_args != NULL)
		free_arr(box->cmd1_args);
	if (box->cmd2_args != NULL)
		free_arr(box->cmd2_args);
	if (box != NULL)
		free(box);
}
