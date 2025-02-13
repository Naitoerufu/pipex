/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:10:26 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/13 12:53:02 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*get_path(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return ("");
}

static char	*file_path(char *name, char **envp)
{
	char	current[4096];
	char	*path;
	int		i;
	int		start;

	if (ft_strncmp(name, "/", 1) == 0 || ft_strncmp(name, "./", 2) == 0)
		return (ft_strdup(name));
	path = get_path(envp);
	i = 0;
	while (path[i])
	{
		start = i;
		while (path[i] && path[i] != ':')
			i++;
		ft_memcpy(current, path + start, i - start);
		current[i - start] = '\0';
		if (current[i - start - 1] != '/')
			ft_strcat(current, "/");
		ft_strcat(current, name);
		if (access(current, X_OK) == 0)
			return (ft_strdup(current));
		while (path[i] == ':')
			i++;
	}
	return (NULL);
}

static void	ft_cmd_parse(int ac, char **av, t_pipex *pipex)
{
	int	count;
	int	arg_pos;

	count = 0;
	arg_pos = 2;
	while (arg_pos < ac - 1)
	{
		pipex->cmd_args[count] = ft_split(av[arg_pos], ' ');
		if (pipex->cmd_args[count][0] == NULL)
			pipex->cmd[count] = ft_strdup("");
		else
			pipex->cmd[count] = ft_strdup(pipex->cmd_args[count][0]);
		count++;
		arg_pos++;
	}
	pipex->cmd_args[count] = NULL;
	pipex->cmd[count] = NULL;
}

static void	ft_cmd_path(t_pipex *pipex)
{
	int		count;
	char	*tmp;

	count = -1;
	while (++count < pipex->cmd_count)
	{
		tmp = pipex->cmd[count];
		pipex->cmd[count] = file_path(tmp, pipex->env);
		free(tmp);
	}
	pipex->cmd[count] = NULL;
}

void	ft_parse(int ac, char **av, t_pipex *pipex)
{
	ft_cmd_parse(ac, av, pipex);
	ft_cmd_path(pipex);
}
