/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:24:24 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/12 16:03:29 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libs/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <stdio.h>

# define BUFFER_SIZE 1

typedef struct s_pipex
{
	int		cmd_count;
	char	*infile;
	char	*outfile;
	char	**cmd;
	char	***cmd_args;
	char	**env;
}			t_pipex;

int			ft_word_count(char **line);
void		ft_free_split(char **to_free);
void		ft_pars(int ac, char **av, t_pipex *pipex);
int			ft_open(t_pipex *pipex);
int		ft_main(t_pipex *pipex);

#endif
