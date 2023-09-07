/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:45:04 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/06 19:15:41 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_cmd(t_pipex *pipex, char *envp[])
{
	int	i;

	i = -1;
	printf("Initialsed cmd_path variable : %s\n", pipex->cmd_path);
	while (envp[++i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			ft_strlcat(pipex->cmd_path, envp[i], ft_strlen(envp[i]));
			break ;
		}
	}
	printf("Path varaible : %s\n", pipex->cmd_path);
}

int	check_files(char *argv[], char *envp[], t_pipex *pipex)
{
	(void)envp;
	if (access(argv[1], F_OK) == -1)
		return (EXIT_FAILURE);
	else
		pipex->infile_fd = open(argv[1], O_RDONLY);
	pipex->cmd1_args = ft_split(argv[2], ' ');
	check_cmd(pipex, envp);
	pipex->cmd2_args = ft_split(argv[3], ' ');
	pipex->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	free_all(pipex);
	return (EXIT_SUCCESS);
}


	//int i = -1;
	//printf("Cmd 1 arguments :\n");
	//while (pipex->cmd1_args[++i])
	//	printf("%s\n", pipex->cmd1_args[i]);
	//i = -1;
	//printf("Cmd 2 arguments :\n");
	//while (pipex->cmd1_args[++i])
	//	printf("%s\n", pipex->cmd2_args[i]);
	//printf("FD for infile : %d\nFD fot outfile : %d\n", pipex->infile_fd, pipex->outfile_fd);