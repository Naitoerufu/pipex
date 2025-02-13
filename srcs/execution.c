/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:18:16 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/13 12:51:22 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_exec(t_pipex *pipex, int index)
{
	if (pipex->cmd[index] != NULL)
		execve(pipex->cmd[index], pipex->cmd_args[index], pipex->env);
	ft_printf(2, "command not found");
	return (127);
}

static int	ft_first_cmd(t_pipex *pipex, int *pipe_fd)
{
	int	fd;

	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	fd = open(pipex->infile, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (ft_exec(pipex, 0));
}

static int	ft_second_cmd(t_pipex *pipex, int *pipe_fd)
{
	int	fd;

	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	fd = open(pipex->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		perror("open");
		return (EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (ft_exec(pipex, 1));
}

static int	ft_children_wait(int pipe_fd[2], int pid1, int pid2)
{
	int	status;

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status));
}

int	ft_action(t_pipex *pipex)
{
	int		pipe_fd[2];
	pid_t	pid[2];

	if (pipe(pipe_fd) < 0)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	pid[0] = fork();
	if (pid[0] < 0)
		return (ft_close_return(pipe_fd));
	else if (pid[0] == 0)
		return (ft_first_cmd(pipex, pipe_fd));
	pid[1] = fork();
	if (pid[1] < 0)
		return (ft_close_return(pipe_fd));
	else if (pid[1] == 0)
		return (ft_second_cmd(pipex, pipe_fd));
	return (ft_children_wait(pipe_fd, pid[0], pid[1]));
}
