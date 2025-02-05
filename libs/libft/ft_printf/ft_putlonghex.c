/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlonghex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:25:46 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/05 11:08:38 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_length(unsigned long long num)
{
	int	out;

	out = 0;
	while (num)
	{
		num /= 16;
		out++;
	}
	return (out);
}

static char	*ft_itohex(unsigned long long num)
{
	int		size;
	char	*out;

	size = ft_length(num);
	out = ft_calloc(size + 1, 1);
	if (!out)
		return (NULL);
	while (num)
	{
		--size;
		out[size] = num % 16;
		if (out[size] <= 9)
			out[size] += '0';
		else
			out[size] += 55;
		num /= 16;
	}
	return (out);
}

int	ft_putlonghex(unsigned long long num, int lowercase, int fd)
{
	char	*s;
	int		out;

	out = 0;
	s = NULL;
	if (num == 0)
		out = ft_putchar_fd('0', fd);
	else
	{
		s = ft_itohex(num);
		if (!s)
			return (0);
		if (lowercase > 0)
			ft_strtolower(s);
		out = ft_putstr_fd(s, fd);
	}
	free(s);
	return (out);
}
