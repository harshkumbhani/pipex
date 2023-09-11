/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:11:27 by harsh             #+#    #+#             */
/*   Updated: 2023/09/11 09:29:48 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_leaks(void)
{
	system("leaks pipex");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	//atexit(check_leaks);
	pipex = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	if (pipex == ALLOC_FAIL)
		handle_error(ERR_MEMORY, pipex);
	if (argc != 5)
		handle_error(ERR_ARG, pipex);
	if (check_files(argv, envp, pipex) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	do_pipe(pipex, envp);
	free_all(pipex);
	return (EXIT_SUCCESS);
}
