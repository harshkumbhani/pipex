/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:09:25 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/07 10:48:21 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int fd[2];
	int	file_fd = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe(fd) == -1)
		return (1);
	int pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0) // Child process cat
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("cat", "cat", "infile", NULL);
	}
	int	pid2 = fork();
	if (pid2 < 0)
		return (4);
	if (pid2 == 0) // child process for wc 
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("wc", "wc", "-l", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
