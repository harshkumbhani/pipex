/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:16:45 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/06 15:00:42 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "library.h"
# include <limits.h>

typedef struct	s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	int		pid1;
	int		pid2;
	char	**cmd1_args;
	char	**cmd2_args;
	char	env[PATH_MAX];
	char	cmd_path[PATH_MAX];
	int		pipe_fd[2];
}	t_pipex;

typedef enum e_errors
{
	SUCCESS = 0,
	ERR_ARG,
	ERR_INFILE,
	ERR_OUTFILE,
	ERR_CMD1,
	ERR_CMD2,
	ERR_MEMORY,
	ERR_PIPE,
	ERR_FORK
}	t_errors;

int	check_files(char *argv[], char *envp[], t_pipex *box);

void	free_all(t_pipex *box);


// Error Handling

void	handle_error(t_errors err, t_pipex *pipe);

#endif