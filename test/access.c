/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:27:03 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/07 12:05:49 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(int argc, char *argv[], char *envp[])
{
	int	ret_val;
	int	fd = open("infile.txt", O_RDONLY);
	ret_val = access("/bin/cat", F_OK);
	if (ret_val != -1)
		printf("Command exits and ret_Value is %d\n", ret_val);
	else
		perror("");
	char	*program = "/bin/cat";
	char	*argvs[] = {"cat", "-e", NULL};
	dup2(fd, STDIN_FILENO);
	//char	*env[] = {"PATH=/bin:/usr/bin", "TERM ="}
	execve(program, argvs, NULL);
	return (0);
}