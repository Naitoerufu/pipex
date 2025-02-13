/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:24:24 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/13 12:52:49 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libs/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

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

int			ft_close_return(int fd[2]);
int			ft_word_count(char **line);
void		ft_free_split(char **to_free);
void		ft_parse(int ac, char **av, t_pipex *pipex);
int			ft_action(t_pipex *pipex);

#endif
