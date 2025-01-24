/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:49:37 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/11/08 14:14:57 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fill(int input, int size, char *out)
{
	int	pos_count;
	int	mult;
	int	negative;

	negative = 0;
	mult = 1;
	pos_count = size - 1;
	if (input < 0)
	{
		negative = 1;
		out[0] = '-';
		mult = -1;
		pos_count = size;
	}
	while (pos_count >= negative)
	{
		out[pos_count] = (input % 10) * mult + 48;
		input /= 10;
		pos_count--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	out[10];
	int		size;
	int		num;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
	{
		out[0] = '0';
		write(fd, out, 1);
	}
	else
	{
		num = n;
		size = 0;
		while (num != 0)
		{
			size++;
			num /= 10;
		}
		ft_fill(n, size, out);
		if (n < 0)
			size++;
		write(fd, out, size);
	}
}
