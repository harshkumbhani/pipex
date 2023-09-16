/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:01:50 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/09/16 08:02:40 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"

typedef struct s_pip_bonus
{
	int		argc;
	int		fd[2];
	int		infile_fd;
	int		outfile_fd;
	char	path[PATH_MAX];
	char	**envp_path;
	char	**argv;
	char	**envp;
}	t_pip_bonus;

#endif