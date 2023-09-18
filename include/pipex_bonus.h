/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsh <harsh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:01:50 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/18 12:56:51 by harsh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"
# include <stdbool.h>

typedef struct s_pip_bonus
{
	bool	here_doc_flag;
	int		argc;
	int		fd[2];
	int		hdfd[2];
	int		infile_fd;
	int		outfile_fd;
	char	path[PATH_MAX];
	char	*tmp;
	char	**envp_path;
	char	**argv;
	char	**envp;
}	t_pip_bonus;

typedef enum e_errors_bonus
{
	ERR_FILEIN,
	ERR_CMD
} t_errors_bonus;

// Error Handler functions

void	handle_error_bonus(t_errors err, t_pip_bonus *pipex);
void	error_bonus(t_errors_bonus err, char *cmd_or_file);

// Utils 

void	init(t_pip_bonus *pipex, int ac, char **av, char **ep);
void	free_bonus(t_pip_bonus *pipex);
void	get_envp_path(t_pip_bonus *pipex);
int		open_file(char *file, int i);
void	close_fds_bonus(t_pip_bonus *pipex);
char	*strjoin_pipex(char *s1, char *s2);

// MUtliple pipe handle function def

int		handle_pipe(t_pip_bonus *pipex);
int		execute(t_pip_bonus *pipex, int i);

#endif