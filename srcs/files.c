/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:53:23 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/05 11:45:26 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_open(t_pipex *pipex)
{
	pid_t	pid;
	char *arg[3];

	arg[0] = ft_strdup("touch");
	arg[1] = ft_strdup(pipex->outfile);
	arg[2] = NULL;
	pipex->fd_in = open(pipex->infile, O_RDONLY);
	if (pipex->fd_in < 0)
		ft_printf(1, "TRISTESSE");
	pipex->fd_out = open(pipex->outfile, O_RDWR);
	if (pipex->fd_out < 0)
	{
		pid = fork();
		if (pid == 0)
		{
			execve("/usr/bin/touch", arg, NULL);
		}
		else
			wait(NULL);
	}
	free(arg[0]);
	free(arg[1]);
	return (0);
}
