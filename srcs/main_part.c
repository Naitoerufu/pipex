/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:18:16 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/11 14:44:05 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_child(t_pipex *pipex, int index, int *fd)
{
	close(fd[0]);
	dup2(pipex->fd_in, 0);
	if (index != pipex->ac - 4)
		dup2(fd[1], 1);
	else
		dup2(pipex->fd_out, 1);
	close(fd[1]);
   	execve(pipex->cmd[index], pipex->cmd_args[index], NULL);
}

void	ft_parent(t_pipex *pipex, int *fd)
{
	wait(NULL);
	close(fd[1]);
	dup2(fd[0], pipex->fd_in);
	close(fd[0]);
}

void	ft_main(t_pipex *pipex, int ac)
{
	int		fd[2];
	int		count;
	pid_t	pid;

	count = 0;
	while(count < ac - 2)
	{
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
			ft_child(pipex, count, fd);
		else
			ft_parent(pipex, fd);
		count++;
	}
}
