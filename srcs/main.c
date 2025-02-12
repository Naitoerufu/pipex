/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:23:46 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/12 16:04:26 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	ft_init(t_pipex *pipex, int ac, char **av, char **env)
{
	pipex->cmd_count = ac - 3;
	pipex->cmd = malloc(sizeof(char *) * (pipex->cmd_count + 1));
	pipex->cmd_args = malloc(sizeof(char **) * (pipex->cmd_count + 1));
	pipex->infile = ft_strdup(av[1]);
	pipex->outfile = ft_strdup(av[ac - 1]);
	pipex->env = env;
}

static void	ft_free(t_pipex *pipex)
{
	int	count;

	ft_free_split(pipex->cmd);
	count = -1;
	while (++count < pipex->cmd_count)
		ft_free_split(pipex->cmd_args[count]);
	free(pipex->cmd_args);
	free(pipex->infile);
	free(pipex->outfile);
}

int	main(int ac, char **av, char **env)
{
	t_pipex pipex;

	if (ac != 5)
	{
		ft_printf(STDERR_FILENO, "Invalid argument quantity!\n");
		exit(EXIT_FAILURE);
	}
	ft_init(&pipex, ac, av, env);
	ft_pars(ac, av, &pipex);
	ft_main(&pipex);
	ft_free(&pipex);
}
