/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:50:13 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/12/04 13:43:02 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	int	ft_length(int num)
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

int	ft_putnbr(int num)
{
	int		size;
	int		out;
	char	*to_print;

	size = 0;
	if (num == -2147483648)
		return (ft_putstr("-2147483648"));
	if (num == 0)
		return (ft_putchar('0'));
	if (num < 0)
	{
		size = 1;
		num *= -1;
	}
	size += ft_length(num);
	to_print = ft_calloc(size + 1, 1);
	to_print[0] = '-';
	while (num)
	{
		to_print[--size] = num % 10 + '0';
		num /= 10;
	}
	out = ft_putstr(to_print);
	free(to_print);
	return (out);
}
