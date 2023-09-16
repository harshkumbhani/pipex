/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 06:24:10 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/16 09:33:36 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pip_bonus	*pipex;
	int			return_value;

	return_value = EXIT_SUCCESS;
	if (argc < 5)
		return (EXIT_FAILURE);
	pipex = (t_pip_bonus *)ft_calloc(1, sizeof(t_pip_bonus));
	if (pipex == ALLOC_FAIL)
		handle_error(ERR_MEMORY, pipex);
	init(pipex, argc, argv, envp);
	//if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	//	heredoc(pipex);
	get_envp_path(pipex);
	return_value = multiple_pipe(pipex);
	free_bonus(pipex);
	return (return_value);
}
