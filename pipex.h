/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:24:24 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/11 14:21:33 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libs/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>

#define BUFFER_SIZE 1

typedef struct s_pipex
{
	int		ac;
	int		fd_in;
	int		fd_out;
	char	*infile;
	char	*outfile;
	char	**cmd;
	char	***cmd_args;
}			t_pipex;

int			ft_word_count(char **line);
void		ft_free_split(char **to_free);
void		ft_pars(int ac, char **av, t_pipex *pipex);
int			ft_open(t_pipex *pipex);
void ft_main(t_pipex *pipex, int index);

#endif
