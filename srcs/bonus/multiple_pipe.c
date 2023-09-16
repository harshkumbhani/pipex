/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:42:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/16 09:50:00 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	first_child(t_pip_bonus *pipex)
{
	int	pid1;

	pid1 = fork();
	if (pid1 < 0)
		perror("Fork Error\n");
	if (pid1 == 0)
	{
		
	}
}

int	multiple_pipe(t_pip_bonus *pipex)
{
	int	status;

	status = EXIT_SUCCESS;
	if (pipe(pipex->fd) == -1)
		handle_error(ERR_PIPE, pipex);
	if (pipex->infile_fd > -1)
		first_child(pipex);
	// middle children 
	last_child(pipex);
}
