/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:16:13 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/12/04 13:43:17 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	int	ft_length(unsigned int num)
{
	int	out;

	out = 0;
	while (num)
	{
		num /= 10;
		out++;
	}
	return (out);
}

unsigned int	ft_putu(unsigned int num)
{
	int		size;
	int		out;
	char	*to_print;

	if (num == 0)
		return (ft_putchar('0'));
	size = ft_length(num);
	to_print = ft_calloc(size + 1, 1);
	while (num)
	{
		to_print[size - 1] = num % 10 + '0';
		num /= 10;
		size--;
	}
	out = ft_putstr(to_print);
	free(to_print);
	return (out);
}
