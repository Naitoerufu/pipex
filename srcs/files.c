/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:53:23 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/06 13:36:22 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_open(t_pipex *pipex)
{
	pipex->fd_in = open(pipex->infile, O_RDONLY);
	if (pipex->fd_in < 0)
		ft_printf(1, "TRISTESSE"); // TODO: make the perror msg
	pipex->fd_out = open(pipex->outfile, O_RDWR | O_CREAT, 0777);
	if (pipex->fd_out < 0)
		ft_printf(1, "TRISTESSE"); // TODO: make the perror msg
	return (0);
}
