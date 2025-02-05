/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:23:46 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/05 16:59:08 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	ft_init(t_pipex *pipex)
{
	pipex->cmd = NULL;
	pipex->cmd_args = NULL;
	pipex->fd_in = 0;
	pipex->fd_out = 0;
	pipex->infile = NULL;
	pipex->outfile = NULL;
}

static void	ft_free(t_pipex *pipex)
{
	int	count;
	
	ft_free_split(pipex->cmd);
	count = 0;
	while (pipex->cmd_args[count])
	{
		ft_free_split(pipex->cmd_args[count]);
		count++;
	}
	free(pipex->cmd_args);
	free(pipex->infile);
	free(pipex->outfile);
}

int main(int ac, char **av)
{
	t_pipex pipex;
	
	
	ft_init(&pipex);
	ft_pars(ac, av, &pipex);
	for (int i = 0; pipex.cmd[i]; i++)
	{
		ft_printf(1, "cmd: %s\n", pipex.cmd[i]);
		ft_printf(1, "args: ");
		for (int j = 0; pipex.cmd_args[i][j]; j++)
		{
			ft_printf(1, "%s, ", pipex.cmd_args[i][j]);
		}
		ft_printf(1, "\n\n");
	}
	ft_printf(1, "infile: %s\noutfile: %s\n\n", pipex.infile, pipex.outfile);
	ft_open(&pipex);
	ft_free(&pipex);
	close(pipex.fd_in);
	close(pipex.fd_out);
}