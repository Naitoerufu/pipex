/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:10:26 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/12 11:55:34 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	ft_arg_pars(int cmd, char **line, t_pipex *pipex)
{
	int	count;
	int	wc;

	count = 0;
	wc = ft_word_count(line);
	pipex->cmd_args[cmd] = malloc(sizeof(char *) * wc + 1);
	while (line[count])
	{
		pipex->cmd_args[cmd][count] = ft_strdup(line[count]);
		count++;
	}
}

static void	ft_cmd_pars(int ac, char **av, t_pipex *pipex)
{
	int		count;
	int		arg_pos;
	char	**tmp;

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

static void	ft_cmd_path(t_pipex *pipex)
{
	int count;

	count = -1;
	while (++count < pipex->cmd_count)
		pipex->cmd[count] = ft_strjoin("/usr/bin/", pipex->cmd[count]);
}

void	ft_pars(int ac, char **av, t_pipex *pipex)
{
	ft_cmd_pars(ac, av, pipex);
	ft_cmd_path(pipex);
}
