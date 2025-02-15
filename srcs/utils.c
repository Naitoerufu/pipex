/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:22:46 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/13 12:50:54 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free_split(char **to_free)
{
	int	count;

	count = 0;
	while (to_free[count])
		free(to_free[count++]);
	free(to_free);
}

int	ft_word_count(char **line)
{
	int	count;

	count = 0;
	while (line[count])
		count++;
	return (count);
}

int	ft_close_return(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
	perror("fork");
	return (EXIT_FAILURE);
}
