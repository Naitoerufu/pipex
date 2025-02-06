/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:18:16 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/06 14:32:25 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_child(t_pipex *pipex, int index, int *fd)
{
    if (index == 0)
    {
	    dup2(pipex->fd_in, 0);
	    close(fd[0]);
	    close(fd[1]);
	    execve(pipex->cmd[index], pipex->cmd_args[index], NULL);
    }
    else
    {
        dup2(fd[0], 0);
        dup2(1, fd[1]);
        close(fd[1]);
    }
}

void	ft_parent(t_pipex *pipex, int index, int *fd)
{
	wait(NULL);
    dup2()
}

void	ft_main(t_pipex *pipex, int index)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		ft_printf(1, "idi nahui");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_printf(1, "idi nahui");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		ft_child(pipex, index, fd);
	else
		ft_parent(pipex, index, fd);
}
