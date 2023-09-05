/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 08:50:40 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/05 09:09:34 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char *argv[])
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid < 0 )
		return (2);
	if (pid == 0) // child process
	{
		close(fd[0]);
		char	str[200];
		printf("Input string: ");
		fgets(str, 200, stdin);
		str[strlen(str) - 1] = '\0';

		int n = strlen(str) + 1;
		write(fd[1], &n, sizeof(int));
		write(fd[1], str, n);
		close(fd[1]);
	}
	else			// Parent process
	{
		close(fd[1]);
		char	readstr[200];
		int		n;

		read(fd[0], &n, sizeof(int));
		read(fd[0], readstr, sizeof(char) * n);
		printf("the input string is \n\n%s\n", readstr);
		close(fd[0]);
		wait(NULL);
	}
	return (0); 
}