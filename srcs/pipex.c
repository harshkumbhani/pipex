/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:11:27 by harsh             #+#    #+#             */
/*   Updated: 2023/10/12 17:24:04 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		return_value;

	return_value = EXIT_SUCCESS;
	if (argc != 5)
		return (EXIT_FAILURE);
	pipex = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	if (pipex == NULL)
		handle_error(ERR_MEMORY, pipex);
	check_files(argv, envp, pipex);
	return_value = do_pipe(pipex, envp);
	free_all(pipex);
	return (return_value);
}
