/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:16:45 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/14 09:37:54 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "library.h"
# include <limits.h>
# include <errno.h>
//# include <wait.h>

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	int		pid1;
	int		pid2;
	char	path[PATH_MAX];
	char	**envp_path;
	char	*tmp;
	char	*cmd_paths[2];
	char	*cmd1_path;
	char	*cmd2_path;
	char	**cmd1_args;
	char	**cmd2_args;
	int		fd[2];
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

// Function to check access of the files and commands

int		check_files(char *argv[], char *envp[], t_pipex *box);

// Function definitions for Utils functions

void	free_all(t_pipex *box);
void	free_arr(char	**arr);
void	print_all_cmds(t_pipex *pipex);

// Error Handling

void	handle_error(t_errors err, t_pipex *pipex);
void	handle_error_return(t_errors err, t_pipex *pipex, char *argv[]);

// Function for handling Pipe operation

int		do_pipe(t_pipex *pipex, char *envp[]);

#endif