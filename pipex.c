/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:11:27 by harsh             #+#    #+#             */
/*   Updated: 2023/09/04 07:34:50 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	int		i = 0;
	while (envp[i])
	{
		printf("Line %d\n", i);
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}
