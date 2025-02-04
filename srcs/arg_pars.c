/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:10:26 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/04 14:57:30 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	ft_arg_pars(int cmd, char **line, t_pipex *pipex)
{
	int	count;
	int	pos;

	count = 0;
	pos = 1;
	pipex->cmd_args[cmd] = malloc(sizeof(char *) * ft_word_count(line));
	while (line[pos])
	{
		pipex->cmd_args[cmd][count] = ft_strdup(line[pos]);
		count++;
		pos++;
	}
}

static void	ft_cmd_pars(int ac, char **av, t_pipex *pipex)
{
	int	count;
	int	arg_pos;
	char **tmp;

	count = 0;
	arg_pos = 2;
	while (arg_pos < ac - 1)
	{
		tmp = ft_split(av[arg_pos], ' ');
		pipex->cmd[count] = ft_strdup(tmp[0]);
		ft_arg_pars(count, tmp, pipex);
		ft_free_split(tmp);
		count++;
		arg_pos++;
	}
}

void	ft_pars(int ac, char **av, t_pipex *pipex)
{
	pipex->infile = ft_strdup(av[1]);
	pipex->outfile = ft_strdup(av[ac - 1]);
	pipex->cmd = malloc(sizeof(char *) * ac - 2);
	pipex->cmd_args = malloc(sizeof(char **) * ac - 2);
	ft_cmd_pars(ac, av, pipex);
}